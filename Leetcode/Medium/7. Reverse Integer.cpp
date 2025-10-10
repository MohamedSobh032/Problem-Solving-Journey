#include <climits>
#include <string>
#include <stdexcept>

class Solution
{
public:
    /**
     * @brief Long arithmetic
     * @details reconstructs the reversed integer using long long arithmetic to skip overflow
     * @complexity: Time: O(d), Space: O(1) where d is the number of digits
     */
    int reverse(int x)
    {
        long long x_rev = 0;
        long long x_cop = (long long)x;

        int mul = 1;
        if (x_cop < 0)
        {
            x_cop *= -1;
            mul = -1;
        }

        while (x_cop != 0)
        {
            x_rev = (x_cop % 10) + (x_rev * 10);
            x_cop /= 10;
        }

        if (x_rev > INT_MAX)
            return 0;
        return x_rev * mul;
    }

    /**
     * @brief String conversion
     * @details reverses the integer by converting it to a string and catching overflow exceptions
     * @complexity: Time: O(d), Space: O(d) where d is the number of digits
     */
    int reverse(int x)
    {
        std::string x_str = std::to_string(x);

        int start_index = x_str[0] == '-' ? 1 : 0;
        for (int i = start_index; i < (x_str.size() - start_index) / 2 + start_index; i++)
        {
            char temp = x_str[i];
            int right = x_str.size() - 1 - (i - start_index);
            x_str[i] = x_str[right];
            x_str[right] = temp;
        }

        try
        {
            return std::stoi(x_str);
        }
        catch (const std::out_of_range &)
        {
            return 0;
        }
    }

    /**
     * @brief Overflow detection
     * @details reverses the integer mathematically while checking for overflow before each operation
     * @complexity: Time: O(d), Space: O(1) where d is the number of digits
     */
    int reverse(int x)
    {
        int res = 0;
        while (x != 0)
        {
            int new_dig = x % 10;
            x /= 10;

            if ((res > INT_MAX / 10) || (res < INT_MIN / 10))
                return 0;

            res = new_dig + (res * 10);
        }
        return res;
    }
};
