#include <queue>
#include <vector>
using namespace std;

class KthLargest
{
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    /**
     * @brief Min-heap with specific length
     * @details initializes a min-heap to maintain the top k largest elements
     * @complexity: Time: O(n log k), Space: O(k)
     */
    KthLargest(int k, vector<int> &nums) : k(k)
    {
        for (const int &num : nums)
        {
            if (pq.size() < k)
                pq.push(num);
            else if (num > pq.top())
            {
                pq.push(num);
                if (pq.size() > k)
                    pq.pop();
            }
        }
    }

    /**
     * @brief Min-heap
     * @details Maintains the k largest values seen so far using a min-heap
     * @complexity: Time: O(log k), Space: O(k)
     */
    int add(int val)
    {
        if (pq.size() < k)
            pq.push(val);
        else if (val > pq.top())
        {
            pq.push(val);
            pq.pop();
        }
        return pq.top();
    }
};