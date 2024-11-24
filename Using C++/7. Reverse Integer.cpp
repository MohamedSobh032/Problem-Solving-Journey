/**
 * @brief First Solution
 * ---> O(n) where n is the number of digits in x
 * ---> Creates a vector to save the digits then reverse
 */
class Solution {
public:
    int reverse(int x) {
        
        int clone = x;
        std::vector<int> nums;
        do {
            nums.push_back(clone % 10);
            clone /= 10;
        } while (clone != 0);

        long long multiplier = 1;
        long long result = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            result += multiplier * nums[i];
            multiplier *= 10;
        }
        if (result > INT_MAX || result < INT_MIN)
            return 0;
        else
            return result;
    }
};

/**
 * @brief Second Solution
 * ---> O(n) where n is the number of digits in x
 * ---> Same as above, but it calculates the digit during the destruction of x
 * ---> Slower because of n condition checking
 */
class Solution {
public:
    int reverse(int x) {

        int rev = 0;
        while (x != 0) {
            int curr_digit = x % 10;
            if (rev > INT_MAX / 10 || rev < INT_MIN / 10)   
                return 0;
            rev = rev * 10 + curr_digit;
            x /= 10;
        }
        return rev;
    }
};