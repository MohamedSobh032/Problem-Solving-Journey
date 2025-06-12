#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /**
     * @brief Max-heap (Priority Queue)
     * @details maintains a max-heap of size k to keep the k closest points by distance from origin
     * @complexity: Time: O(n log k), Space: O(k)
     */
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        auto func = [](const vector<int> &a, const vector<int> &b)
        {
            return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(func)> pq(func);
        for (const auto &point : points)
        {
            pq.push(point);
            if (pq.size() > k)
                pq.pop();
        }

        vector<vector<int>> res;
        while (!pq.empty())
        {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }

    /**
     * @brief Partial sort
     * @details partially sorts the first k elements to be the closest in distance without full sorting
     * @complexity: Time: O(n log k), Space: O(1)
     */
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        partial_sort(points.begin(), points.begin() + k, points.end(), [](const vector<int> &a, const vector<int> &b)
                     { return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]); });
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};