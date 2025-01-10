#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    int n; std::cin >> n;
    int x, y, z; std::cin >> x >> y >> z;
    std::vector<int> dp(n + 1, -1); dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (i >= x && dp[i - x] != -1) dp[i] = std::max(dp[i], dp[i - x] + 1);
        if (i >= y && dp[i - y] != -1) dp[i] = std::max(dp[i], dp[i - y] + 1);
        if (i >= z && dp[i - z] != -1) dp[i] = std::max(dp[i], dp[i - z] + 1);
    }
    std::cout << (dp[n] == -1 ? 0 : dp[n]);
}