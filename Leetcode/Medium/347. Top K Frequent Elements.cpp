#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
    /**
     * @brief Heap
     * @details Use a hash map to count frequencies, then a max heap to get top k elements
     * @complexity: Time: O(n log(n)), Space: O(n)
     */
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> nmap;
        for (const auto &num : nums)
            nmap[num]++;

        auto comp = [](const pair<int, int> &a, const pair<int, int> &b) -> bool
        { return a.second < b.second; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);

        for (const auto &pair : nmap)
            pq.push(pair);

        vector<int> topK;
        for (int i = 0; i < k && !pq.empty(); i++, pq.pop())
            topK.emplace_back(pq.top().first);
        return topK;
    }

    /**
     * @brief Bucket Sort
     * @details Count frequencies and group numbers by frequency into buckets; collect top k from highest buckets
     * @complexity: Time: O(n), Space: O(n)
     */
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> nmap;
        for (const auto &num : nums)
            nmap[num]++;

        vector<vector<int>> bucket(nums.size() + 1);
        for (const auto &pair : nmap)
            bucket[pair.second].emplace_back(pair.first);

        vector<int> topK;
        for (int i = bucket.size() - 1; i >= 0; i--)
        {
            for (const int &num : bucket[i])
            {
                topK.emplace_back(num);
                if (topK.size() == k)
                    return topK;
            }
        }
        return topK;
    }
};