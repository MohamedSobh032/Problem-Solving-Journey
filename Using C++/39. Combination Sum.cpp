
/**
 * @brief First Solution
 * ---> O(n * 2^n)
 * ---> Recursive Solution, with using sets and sort to prevent repeated values
 */
class Solution
{
public:
    void rec(const vector<int> &candidates, const int &target, int curr_sum, vector<int> curr_elems, set<vector<int>> &ret)
    {

        // base-case
        if (150 == curr_elems.size() || curr_sum > target)
            return;
        if (curr_sum == target)
        {
            sort(curr_elems.begin(), curr_elems.end());
            ret.insert(curr_elems);
            return;
        }

        // recursion
        for (size_t i = 0; i < candidates.size(); i++)
        {
            curr_elems.push_back(candidates[i]);
            rec(candidates, target, curr_sum + candidates[i], curr_elems, ret);
            curr_elems.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        set<vector<int>> ret;
        rec(candidates, target, 0, {}, ret);
        vector<vector<int>> rett;
        for (const auto &vec : ret)
            rett.push_back(vec);
        return rett;
    }
};

/**
 * @brief Second Solution
 * ---> O(2^target)
 * ---> Recursive take or not take
 */
class Solution
{
public:
    void rec(const vector<int> &candidates, const int &target, int i, vector<int> &curr_elems, int curr_sum, vector<vector<int>> &ret)
    {
        // base-case
        if (curr_sum == target)
        {
            ret.push_back(curr_elems);
            return;
        }
        if (150 == curr_elems.size() || curr_sum > target || i >= candidates.size())
            return;

        // recursion
        curr_elems.push_back(candidates[i]);
        rec(candidates, target, i, curr_elems, curr_sum + candidates[i], ret);
        curr_elems.pop_back();
        rec(candidates, target, i + 1, curr_elems, curr_sum, ret);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ret;
        vector<int> comb;
        rec(candidates, target, 0, comb, 0, ret);
        return ret;
    }
};