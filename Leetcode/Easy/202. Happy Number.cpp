#include <unordered_set>
using namespace std;

class Solution
{
private:
    int compute_next(int n)
    {
        int current_sum = 0;
        while (n != 0)
        {
            int digit = n % 10;
            current_sum += digit * digit;
            n /= 10;
        }
        return current_sum;
    }

public:
    /**
     * @brief Visited Set
     * @details Stores visited numbers to detect loops
     * @complexity: Time: O(logn), Space: O(k)
     * @note `k` is the number of unique elements visited
     */
    bool isHappy(int n)
    {
        unordered_set<int> set;
        while (n != 1 && !set.count(n))
        {
            set.insert(n);
            n = compute_next(n);
        }
        return n == 1;
    }

    /**
     * @brief Floyd's cycle detection
     * @details Uses slow and fast pointers to detect a cycle in constant space
     * @complexity: Time: O(log n), Space: O(1)
     */
    bool isHappy(int n)
    {
        int slow = compute_next(n);
        int fast = compute_next(slow);
        while (slow != fast && slow != 1)
        {
            slow = compute_next(slow);
            fast = compute_next(compute_next(fast));
        }
        return slow == 1;
    }
};