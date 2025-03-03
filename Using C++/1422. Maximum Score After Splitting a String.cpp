/**
 * @brief First Solution
 * -- Time Complexity: O(n^2)
 * -- Space Complexity: O(1)
 * -- Brute-force approach, tries all possible splits and calculates the score
 */
class Solution
{
public:
    int maxScore(string s)
    {
        int max_score = INT_MIN;
        for (int i = 1; i < s.size(); i++)
        {
            int left_zeros = 0;
            int right_ones = 0;
            for (int j = 0; j < i; j++)
                left_zeros += (s[j] == '0');
            for (int j = s.size() - 1; j >= i; j--)
                right_ones += (s[j] == '1');
            max_score = std::max(max_score, left_zeros + right_ones);
        }
        return max_score;
    }
};

/**
 * @brief Second Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(n)
 * -- Optimized approach, uses two arrays to store the number of zeros and ones to the left and right of each index
 */
class Solution
{
public:
    int maxScore(string s)
    {
        int N = s.size();
        int max_score = INT_MIN;
        std::vector<int> zeros(N - 1, 0);
        std::vector<int> ones(N - 1, 0);

        zeros[0] = (s[0] == '0');
        for (int i = 1; i < N - 1; i++)
            zeros[i] = zeros[i - 1] + (s[i] == '0');

        ones[N - 2] = (s[N - 1] == '1');
        for (int i = N - 3; i >= 0; i--)
            ones[i] = ones[i + 1] + (s[i + 1] == '1');

        for (int i = 0; i < N - 1; i++)
            max_score = std::max(max_score, zeros[i] + ones[i]);
        return max_score;
    }
};

/**
 * @brief Third Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(1)
 * -- Further optimized approach, uses two variables to store the current number of zeros and ones
 */
class Solution
{
public:
    int maxScore(string s)
    {
        int ones = 0;
        int zeros = 0;
        int best = INT_MIN;
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (s[i] == '1')
                ones++;
            else
                zeros++;
            best = std::max(best, zeros - ones);
        }
        ones += (s.back() == '1');
        return best + ones;
    }
};