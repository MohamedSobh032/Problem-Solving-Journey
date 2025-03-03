/**
 * @brief First Solution
 * -- O(n * nlogn)
 * -- get the anagrams by sorting, group by hashmap
 */
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {

        unordered_map<string, vector<string>> nmap;
        for (const auto &str : strs)
        {
            string temp = str;
            std::sort(temp.begin(), temp.end());
            nmap[temp].push_back(str);
        }

        vector<vector<string>> ret;
        for (const auto &pair : nmap)
            ret.push_back(pair.second);
        return ret;
    }
};