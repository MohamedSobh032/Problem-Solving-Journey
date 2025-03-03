/**
 * @brief ALL SOLUTIONS ARE THE SAME WITH DIFFERENT IMPLEMENTATIONS
 * @note RECURSION OR WHILE LOOP
 * @note DIVIDE BY 2 OR SHIFT LEFT BY 1
 * @note THIS CREATES 4 DIFFERENT SOLUTIONS
 */
class Solution
{
public:
    int hammingWeight(int n)
    {
        if (n == 0)
            return 0;
        return (n & 1) + hammingWeight(n / 2);
    }
};
class Solution
{
public:
    int hammingWeight(int n)
    {
        if (n == 0)
            return 0;
        return (n & 1) + hammingWeight(n >> 1);
    }
};
class Solution
{
public:
    int hammingWeight(int n)
    {
        int sum = 0;
        while (n != 0)
        {
            sum += n & 1;
            n = n >> 1;
        }
        return sum;
    }
};
class Solution
{
public:
    int hammingWeight(int n)
    {
        int sum = 0;
        while (n != 0)
        {
            sum += n & 1;
            n = n / 2;
        }
        return sum;
    }
};