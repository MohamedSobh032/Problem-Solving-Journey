/**
 * @brief First/Only Solution
 * ---> O(n), where n is the number of 1's of the xor
 * ---> Got the algorithm from Computer Networks-1 course
 */
class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int res = x ^ y;
        int sum = 0;
        while (res > 0)
        {
            sum += res & 1;
            res = res >> 1;
        }
        return sum;
    }
};