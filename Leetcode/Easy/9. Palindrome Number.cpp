#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * @brief Vector then Normal-Palindrome
     * @details extracts digits into a vector and compares from both ends
     * @complexity: Time: O(d), Space: O(d) where d is the number of digits
     */
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;

        std::vector<int> vec;
        int temp = x;
        while (temp != 0)
        {
            vec.push_back(temp % 10);
            temp /= 10;
        }

        int len = vec.size();
        for (int i = 0; i < len / 2; i++)
            if (vec[i] != vec[len - 1 - i])
                return false;
        return true;
    }

    /**
     * @brief Reversed Integer
     * @details reverses the number mathematically and then compares with the original
     * @complexity: Time: O(d), Space: O(1) where d is the number of digits
     */
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;

        long x_rev = 0;
        int x_cop = x;
        while (x_cop > 0)
        {
            x_rev = (x_rev * 10) + (x_cop % 10);
            x_cop /= 10;
        }

        return x_rev == x;
    }
};
