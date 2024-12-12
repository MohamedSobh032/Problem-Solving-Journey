#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int solve(int i, int current_budget, const vector<vector<int>>& items, vector<vector<int>>& dp) {
    
    if (i == (int)items.size())
        return current_budget;
    
    if (dp[i][current_budget] != -1)
        return dp[i][current_budget];
    
    int result = INT_MAX;
    for (const auto p: items[i])
        if (current_budget >= p)
            result = std::min(result, solve(i + 1, current_budget - p, items, dp));
    
    return dp[i][current_budget] = result;
}

int main() {

    int B, T; std::cin >> B >> T;
    std::vector<std::vector<int>> items(T);
    for (int i = 0; i < T; i++) {
        int size; std::cin >> size;
        for (int j = 0; j < size; j++) {
            int temp; std::cin >> temp;
            items[i].push_back(temp);
        }
    }
    
    vector<vector<int>> dp(21, vector<int>(201, -1));
    int res = solve(0, B, items, dp);
    if (res == INT_MAX)
        cout << "no solution";
    else
        cout << B - res;
    
}
