#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * @brief Max-heap
     * @details pops the biggest 2 elements, and then pushes the difference, breaks if 0 is the max element for edge handling
     * @complexity: Time: O(n log(n)), Space: O(n)
     */
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int, vector<int>> pq(stones.begin(), stones.end());
        int x = 0, y = 0;
        while (!pq.empty())
        {
            y = pq.top();
            pq.pop();

            if (pq.empty() || y == 0)
                break;

            x = pq.top();
            pq.pop();

            pq.push(y - x);
        }
        return y;
    }

    /**
     * @brief Max-heap
     * @details same as above, but breaks if there are less than 2 elements in the queue and do not add 0s in the queue
     * @complexity: Time: O(n log(n)), Space: O(n)
     */
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int, vector<int>> pq(stones.begin(), stones.end());
        int x = 0, y = 0;
        while (pq.size() >= 2)
        {
            y = pq.top();
            pq.pop();

            x = pq.top();
            pq.pop();

            if (y != x)
                pq.push(y - x);
        }
        return pq.empty() ? 0 : pq.top();
    }
};