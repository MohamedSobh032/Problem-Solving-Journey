class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ones = 0, twos = 0;
        for (const int &num : nums)
        {
            ones ^= num & ~twos;
            twos ^= num & ~ones;
        }
        return ones;
    }
};