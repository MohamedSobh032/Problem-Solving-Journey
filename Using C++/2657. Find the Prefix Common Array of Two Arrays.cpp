/**
 * @brief First Solution
 * -- Time Complexity: O(n^3)
 * -- Space Complexity: O(1)
 * -- Brute-force approach, for each index at C
 *    iterates on all possible indexes of A and B to find if common element exists.
 */
class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {
        int n = A.size();
        std::vector<int> C(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                for (int k = 0; k <= i; k++)
                {
                    if (A[j] != B[k])
                        continue;
                    C[i]++;
                    break;
                }
            }
        }
        return C;
    }
};

/**
 * @brief Second Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(n)
 * -- Counts the frequency of each number, and uses prefix variable to keep track of common elements
 */
class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {
        int n = A.size(), common_count = 0;
        std::vector<int> C(n, 0), freqs(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            common_count += (++freqs[A[i]] == 2);
            common_count += (++freqs[B[i]] == 2);
            C[i] = common_count;
        }
        return C;
    }
};