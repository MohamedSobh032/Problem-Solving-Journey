#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    /**
     * @brief range-compression scan
     * @details iterate through nums, and whenever a streak ends, emit the range and reset the start index
     * @complexity: Time: O(n), Space: O(1)
     */
    vector<string> summaryRanges(vector<int> &nums)
    {
        std::vector<std::string> s;
        int prev = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == nums.size() - 1 || nums[i] + 1 != nums[i + 1])
            {
                string v = to_string(nums[prev]);
                if (prev != i)
                    v += "->" + to_string(nums[i]);
                s.push_back(v);
                prev = i + 1;
            }
        }

        return s;
    }

    /**
     * @brief range-expansion scan
     * @details for each index expand the streak forward, emit the range, then jump i to the end of that streak
     * @complexity: Time: O(n), Space: O(1)
     */
    vector<string> summaryRanges(vector<int> &nums)
    {
        std::vector<std::string> s;
        for (int i = 0; i < nums.size(); i++)
        {
            int j = i;
            while (j != nums.size() - 1 && nums[j] + 1 == nums[j + 1])
            {
                j++;
            }

            string v = to_string(nums[i]);
            if (i < j)
                v += "->" + to_string(nums[j]);
            s.push_back(v);

            i = j;
        }

        return s;
    }
};
