/**
 * @brief First Solution
 * -- Time Complexity: O(3^N)
 * -- Space Complexity: O(3^N)
 * -- Brute-force solution to try all costs on each day, and find the minimum sum when it reaches the end
 */
class Solution
{
public:
    void rec(const std::vector<int> &days, const std::vector<int> &costs,
             int end_date, int &least_sum, int index, int curr_sum)
    {

        if (index == days.size())
        {
            least_sum = std::min(least_sum, curr_sum);
            return;
        }

        if (end_date >= days[index])
            rec(days, costs, end_date, least_sum, index + 1, curr_sum);
        else
        {
            rec(days, costs, days[index], least_sum, index + 1, curr_sum + costs[0]);
            rec(days, costs, days[index] + 6, least_sum, index + 1, curr_sum + costs[1]);
            rec(days, costs, days[index] + 29, least_sum, index + 1, curr_sum + costs[2]);
        }
    }

    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int least_sum = INT_MAX;
        rec(days, costs, 0, least_sum, 0, 0);
        return least_sum;
    }
};

/**
 * @brief Second Solution
 * -- Time Complexity: O(N)
 * -- Space Complexity: O(N)
 * -- Dynamic programming top-down solution to store the minimum sum when it reaches the end
 */
class Solution
{
public:
    int rec(const std::vector<int> &days, const std::vector<int> &costs, std::vector<int> &dp, int index)
    {
        if (index >= days.size())
            return 0;
        if (dp[index] != INT_MAX)
            return dp[index];

        int cost1 = costs[0] + rec(days, costs, dp, index + 1);

        int j = index;
        while (j < days.size() && days[j] < days[index] + 7)
            j++;
        int cost7 = costs[1] + rec(days, costs, dp, j);

        j = index;
        while (j < days.size() && days[j] < days[index] + 30)
            j++;
        int cost30 = costs[2] + rec(days, costs, dp, j);

        dp[index] = std::min({cost1, cost7, cost30});
        return dp[index];
    }

    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        std::vector<int> dp(days.size(), INT_MAX);
        return rec(days, costs, dp, 0);
    }
};

/**
 * @brief Third Solution
 * -- Time Complexity: O(N)
 * -- Space Complexity: O(1)
 * -- Dynamic programming bottom-up solution to store the minimum sum when it reaches the end
 */
class Solution
{
public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {

        std::vector<int> dp(367, 0);
        std::vector<bool> travel_day(367, false);
        for (const auto &day : days)
            travel_day[day] = true;

        for (int i = 365; i >= 1; i--)
        {
            if (!travel_day[i])
            {
                dp[i] = dp[i + 1];
                continue;
            }
            dp[i] = std::min({costs[0] + dp[i + 1],
                              costs[1] + dp[std::min(365, i + 7)],
                              costs[2] + dp[std::min(365, i + 30)]});
        }
        return dp[1];
    }
};