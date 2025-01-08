/**
 * @brief First Solution
 * -- Time Complexity: O(n^2 * m^2)
 * -- Space Complexity: O(1)
 * -- Brute-force approach, tries all possible pairs and checks if they are prefix and suffix by creating substrings
 */
class Solution {
public:
    bool isPrefixAndSuffix(const std::string& str1, const std::string& str2) {
    
        int n1 = str1.size(), n2 = str2.size();
        if (n1 > n2) return false;
        return str2.substr(0, n1) == str1 && str2.substr(n2 - n1, n1) == str1;
    }

    int countPrefixSuffixPairs(std::vector<std::string>& words) {
        
        int counter = 0;
        for (int i = 0; i < words.size(); i++)
            for (int j = i + 1; j < words.size(); j++)
                counter += isPrefixAndSuffix(words[i], words[j]);
        return counter;
    }
};