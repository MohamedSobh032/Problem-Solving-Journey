#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main() {
    int x, y; std::cin >> x >> y;
    vector<vector<long long>> dp(x + 1, vector<long long>(y + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            if (i == 0 && j == 0) continue;
            if (i > 0) dp[i][j] += dp[i - 1][j];
            if (j > 0) dp[i][j] += dp[i][j - 1];
        }
    }
    cout << dp[x][y];
}