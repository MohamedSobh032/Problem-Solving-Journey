/**
 * @brief First Solution
 * -- Time Complexity: O(W + Q)
 * -- Space Complexity: O(W)
 * -- Calculates the accumulated number of words that start and end with a vowel
 *    Then calculates the number of words that start and end with a vowel in a given range
 */
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {

        int n = words.size(); std::vector<int> Prefix(n + 1, 0);
        std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'}; 
        for (int i = 0; i < n; i++) {
            Prefix[i + 1] = Prefix[i];
            if (vowels.count(words[i].front()) && vowels.count(words[i].back())) Prefix[i + 1]++;  
        }

        std::vector<int> ANS; 
        for (auto& query : queries) {
            int L = query[0], R = query[1];  
            ANS.push_back(Prefix[R + 1] - Prefix[L]);  
        }

        return ANS;  
    }
};

/**
 * @brief Second Solution
 * -- Time Complexity: O(W + Q)
 * -- Space Complexity: O(W)
 * -- Calculates the accumulated number of words that start and end with a vowel
 *    Then calculates the number of words that start and end with a vowel in a given range
 *    Same as above, but using a function to check if a character is a vowel so no need for a set
 */
class Solution {
public:
    bool isVowel(const char& c)
    { return (c == 'a' || c == 'e' || c == 'i' || c == 'i' || c == 'o' || c == 'u'); }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {

        std::vector<int> acc(words.size(), 0);
        for (int i = 0; i < words.size(); i++) {
            if (i != 0) acc[i] = acc[i - 1];
            if (isVowel(words[i][0]) && isVowel(words[i].back())) acc[i] += 1;
        }

        std::vector<int> ans(queries.size(), 0);
        for (int i = 0; i < queries.size(); i++)
            ans[i] = acc[queries[i][1]] - (queries[i][0] != 0 ? acc[queries[i][0] - 1] : 0);
        return ans;
    }
};