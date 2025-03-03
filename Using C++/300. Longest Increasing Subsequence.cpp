/**
 * @brief First Solution
 * --- m4 3aref agib complexity
 * --- Get all possible subsequence, then check if sorted or not and checks if it is a maximum or not
 */
class Solution
{
public:
    bool is_sorted_strictly(const std::vector<int> &curr)
    {
        for (int i = 1; i < curr.size(); ++i)
            if (curr[i] <= curr[i - 1])
                return false;
        return true;
    }

    void rec(const std::vector<int> &nums, vector<int> curr, int index, int &maximum)
    {
        // base case
        if (index >= nums.size())
        {
            if (is_sorted_strictly(curr) && curr.size() > maximum)
                maximum = curr.size();
            return;
        }

        // recursion
        rec(nums, curr, index + 1, maximum);
        curr.push_back(nums[index]);
        rec(nums, curr, index + 1, maximum);
    }

    int lengthOfLIS(vector<int> &nums)
    {
        int maximum = 0;
        rec(nums, {}, 0, maximum);
        return maximum;
    }
};

/**
 * @brief Second Solution
 * -- O(n^2)
 * -- Bottom-up dynamic programming
 * -- Finds maximum from 0 to i for every LIS
 */
class Solution
{
public:
    int find_max(const vector<int> &nums, const vector<int> &lis, const int &val, const int &until)
    {
        int max = 0;
        for (std::size_t i = 0; i < until; i++)
            if (nums[i] < val && max < lis[i])
                max = lis[i];
        return max;
    }

    int lengthOfLIS(vector<int> &nums)
    {

        std::vector<int> LIS(nums.size(), 0);
        for (std::size_t i = 0; i < nums.size(); i++)
            LIS[i] = max(1, find_max(nums, LIS, nums[i], i) + 1);
        return *std::max_element(LIS.begin(), LIS.end());
    }
};

/**
 * @brief Third Solution
 * --- O(n^2)
 * --- top down dynamic programming approach, by finding the strictly increaing subsequence in the second for loop
 */
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        std::vector<int> lis(nums.size(), 1);
        for (int i = nums.size() - 1; i >= 0; i--)
            for (int j = i + 1; j < nums.size(); j++)
                if (nums[i] < nums[j])
                    lis[i] = std::max(lis[i], 1 + lis[j]);

        return *std::max_element(lis.begin(), lis.end());
    }
};

/**
 * @brief Fourth Solution
 * --- O(nlogn)
 * --- finds the index of the element if it can't construct it to be strictly sorted
 */
class Solution
{
public:
    int binarySearch(const vector<int> &arr, int target)
    {
        int left = 0;
        int right = arr.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (arr[mid] == target)
                return mid;
            else if (arr[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }

    int lengthOfLIS(vector<int> &nums)
    {
        std::vector<int> res;
        for (const auto &n : nums)
        {
            if (res.empty() || res.back() < n)
                res.push_back(n);
            else
            {
                int idx = binarySearch(res, n);
                res[idx] = n;
            }
        }
        return res.size();
    }
};