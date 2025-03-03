/**
 * @brief First Solution
 * -- Time Complexity: O(nm)
 * -- Space Complexity: O(n + m)
 * -- Creates a hashmap for every word in words1 and words2 to get the subsets
 */
class Solution
{
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        std::vector<std::unordered_map<char, int>> freqs1(words1.size());
        for (int i = 0; i < words1.size(); i++)
            for (const char &c : words1[i])
                freqs1[i][c]++;

        std::vector<std::unordered_map<char, int>> freqs2(words2.size());
        for (int i = 0; i < words2.size(); i++)
            for (const char &c : words2[i])
                freqs2[i][c]++;

        std::vector<std::string> uni;
        for (int i = 0; i < words1.size(); i++)
        {
            bool flag = true;
            for (int j = 0; j < words2.size(); j++)
            {
                for (const char &c : words2[j])
                    if (freqs1[i][c] < freqs2[j][c])
                    {
                        flag = false;
                        break;
                    }
                if (!flag)
                    break;
            }
            if (flag)
                uni.emplace_back(words1[i]);
        }

        return uni;
    }
};

/**
 * @brief Second Solution
 * -- Time Complexity: O(nm)
 * -- Space Complexity: O(n + m)
 * -- Same approach but creates a hashmap for every word in words1, and a single hashmap for all words2
 */
class Solution
{
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {

        std::unordered_map<char, int> maxFreq;
        for (const auto &word : words2)
        {
            std::unordered_map<char, int> freq;
            for (const char &c : word)
            {
                freq[c]++;
                maxFreq[c] = std::max(maxFreq[c], freq[c]);
            }
        }

        std::vector<std::string> uni;
        for (const auto &word : words1)
        {
            std::unordered_map<char, int> freq;
            for (const char &c : word)
                freq[c]++;
            bool isUniversal = true;
            for (const auto &[charReq, freqReq] : maxFreq)
            {
                if (freq[charReq] < freqReq)
                {
                    isUniversal = false;
                    break;
                }
            }
            if (isUniversal)
                uni.emplace_back(word);
        }

        return uni;
    }
};

/**
 * @brief Third Solution
 * -- Time Complexity: O(nm)
 * -- Space Complexity: O(1)
 * -- Same approach but computes the max frequency in different iteration for optimization
 *    Also, uses array instead of hashmap for better performance
 *    Also, does not create a hashmap for every word in words1, instead only dummy array
 */
class Solution
{
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        int universal[26] = {0};
        int dummy[26];
        for (const auto &word : words2)
        {
            memset(dummy, 0, sizeof dummy);
            for (const char &ch : word)
                dummy[ch - 'a']++;
            for (int i = 0; i < 26; i++)
                universal[i] = max(universal[i], dummy[i]);
        }

        std::vector<std::string> universals;
        for (const auto &word : words1)
        {
            memset(dummy, 0, sizeof dummy);
            for (char ch : word)
                dummy[ch - 'a']++;
            int i = 0;
            for (; i < 26; i++)
                if (universal[i] > dummy[i])
                    break;
            if (i == 26)
                universals.emplace_back(word);
        }

        return universals;
    }
};