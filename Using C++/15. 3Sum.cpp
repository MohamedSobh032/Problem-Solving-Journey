/**
 * @brief First Solution
 * ---> O(n^3)
 * ---> brute-force with sorting a set to remove duplicates
 */
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        vector<vector<int>> ret;
        set<vector<int>> uniqueTriplets;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                for (int k = 0; k < nums.size(); k++)
                {
                    if ((nums[i] + nums[j] + nums[k] == 0) && (i != j) && (i != k) && (j != k))
                    {
                        vector<int> triplet = {nums[i], nums[j], nums[k]};
                        sort(triplet.begin(), triplet.end());
                        uniqueTriplets.insert(triplet);
                    }
                }
            }
        }
        for (const auto &triplet : uniqueTriplets)
            ret.push_back(triplet);
        return ret;
    }
};

/**
 * @brief Second Solution
 * ---> O(n2)
 * ---> Get target for each number, then two sum for a unsorted array
 */
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        vector<vector<int>> vec;
        set<vector<int>> uniqueTriplets;
        for (int i = 0; i < nums.size(); i++)
        {
            unordered_map<int, int> nmap;
            int target = 0 - nums[i];
            for (int j = 0; j < nums.size(); j++)
            {
                int toGet = target - nums[j];
                if (nmap.find(toGet) != nmap.end() && (i != j) && (i != nmap[toGet]) && (j != nmap[toGet]))
                {
                    vector<int> triplet = {nums[i], nums[j], toGet};
                    sort(triplet.begin(), triplet.end());
                    uniqueTriplets.insert(triplet);
                }
                nmap[nums[j]] = j;
            }
        }
        for (const auto &triplet : uniqueTriplets)
            vec.push_back(triplet);
        return vec;
    }
};

/**
 * @brief Third Solution
 * ---> O(n^2 * logn)
 * ---> Get target for each number, then two sum for a sorted array
 */
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> vec;
        std::set<std::vector<int>> s;
        for (int i = 0; i < nums.size(); i++)
        {
            int target = 0 - nums[i];
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k)
            {
                if (nums[j] + nums[k] == target)
                {
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if (nums[j] + nums[k] < target)
                    j++;
                else
                    k--;
            }
        }
        for (const auto &triplet : s)
            vec.push_back(triplet);
        return vec;
    }
};

/**
 * @brief Fourth Solution
 * ---> O(n^2)
 * ---> Same as above, but removes the duplicates addition in the first place so no need to use set
 */
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> vec;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0)
                {
                    vec.emplace_back(std::vector<int>{nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1])
                        j++;
                    while (j < k && nums[k] == nums[k - 1])
                        k--;
                    j++;
                    k--;
                }
                else if (sum < 0)
                    j++;
                else
                    k--;
            }
        }
        return vec;
    }
};