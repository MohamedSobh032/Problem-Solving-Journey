/**
 * @brief First Solution
 * -- O(klogn)
 * -- Solution described in comments
 */
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> ret;
        // put frequencies in a hashmap
        unordered_map<int, int> nmap;
        for (const auto &num : nums)
            nmap[num]++;

        // create a custom priority queue
        auto comp = [](const pair<int, int> &a, const pair<int, int> &b)
        {
            return a.second < b.second || (a.second == b.second && a.first > b.first); // max-heap by frequency
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);

        // put all the value to be sorted by frequency
        for (const auto &pair : nmap)
            pq.push(pair);

        // find top K elements, append them in vector, return
        for (int i = 0; i < k; i++)
        {
            ret.push_back(pq.top().first);
            pq.pop();
        }
        return ret;
    }
};

/**
 * @brief Second Solution
 * -- O(n)
 * -- Solution described in comments
 */
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        // put frequencies in a hashmap
        unordered_map<int, int> nmap;
        for (const auto &num : nums)
            nmap[num]++;
        // apply bucket sort
        vector<vector<int>> freqs(nums.size() + 1);
        for (const auto &pair : nmap)
            freqs[pair.second].push_back(pair.first);
        // put result in vector and return
        vector<int> ret;
        for (int i = freqs.size() - 1; i >= 0; i--)
        {
            for (int j = 0; j < freqs[i].size(); j++)
            {
                ret.push_back(freqs[i][j]);
                k--;
                if (k == 0)
                    return ret;
            }
        }
        return ret;
    }
};