#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /**
     * @brief Hash table
     * @details for each string, sorts it and place it in a group by hashing, then converts the map to vector before returning it.
     * @complexity: Time: O(n m log(m) + k), Space: O(n m)
     * @note `n` is the number of strings, `m` is the size of each string, 'k' is the number of groups, worst case of `k` is `n`, so it can be ignored.
     */
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> map;
        for (const string &str : strs)
        {
            string nstr = str;
            sort(nstr.begin(), nstr.end());
            map[nstr].emplace_back(str);
        }

        vector<vector<string>> vect(map.size());
        int i = 0;
        for (const auto &pair : map)
        {
            vect[i] = pair.second;
            i++;
        }
        return vect;
    }
};