#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    /**
     * @brief Brute-force comparison
     * @details for each day, scans forward to find the next warmer temperature
     * @complexity: Time: O(n²), Space: O(1)
     */
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        std::vector<int> days(n, 0);
        for (int i = 0; i < n - 1; i++)
        {
            int j = i + 1;
            for (; j < n; j++)
                if (temperatures[j] > temperatures[i])
                    break;
            days[i] = j >= n ? 0 : j - i;
        }
        return days;
    }

    /**
     * @brief Monotonic stack
     * @details uses a stack to track unresolved indices and find the next warmer day
     * @complexity: Time: O(n), Space: O(n)
     */
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        std::vector<int> days(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && temperatures[i] > temperatures[st.top()])
            {
                int j = st.top();
                st.pop();
                days[j] = i - j;
            }
            st.push(i);
        }
        return days;
    }
};
