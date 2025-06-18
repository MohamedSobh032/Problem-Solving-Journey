#include <vector>
#include <queue>
using namespace std;

class Solution
{
private:
    int quick_select(vector<int> &nums, int left, int right, int target)
    {
        if (left == right)
            return nums[left];

        int pivot = nums[left], l = left, r = right;

        while (l <= r)
        {
            while (l <= r && nums[l] < pivot)
                l++;
            while (l <= r && nums[r] > pivot)
                r--;

            if (l <= r)
            {
                swap(nums[l], nums[r]);
                l++;
                r--;
            }
        }

        if (target <= r)
            return quick_select(nums, left, r, target);
        else if (target >= l)
            return quick_select(nums, l, right, target);
        else
            return nums[target];
    }

public:
    /**
     * @brief Min-heap (priority queue)
     * @details maintains a heap of size k to keep track of the k largest elements
     * @complexity: Time: O(n log k), Space: O(k)
     */
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (const int &num : nums)
        {
            pq.push(num);
            if (pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }

    /**
     * @brief Quick Select
     * @details uses partitioning logic to directly find the (n-k)th smallest element
     * @complexity: Time: O(n) average, O(n^2) worst case, Space: O(1)
     */
    int findKthLargest(vector<int> &nums, int k)
    {
        int target = nums.size() - k;
        return quick_select(nums, 0, nums.size() - 1, target);
    }
};