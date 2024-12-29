#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// bottom up
int main() {
    int n; std::cin >> n;
    int x, y, z; std::cin >> x >> y >> z;
    std::vector<int> dp(n + 1, -1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (i >= x && dp[i - x] != -1) dp[i] = std::max(dp[i], dp[i - x] + 1);
        if (i >= y && dp[i - y] != -1) dp[i] = std::max(dp[i], dp[i - y] + 1);
        if (i >= z && dp[i - z] != -1) dp[i] = std::max(dp[i], dp[i - z] + 1);
    }
    std::cout << (dp[n] == -1 ? 0 : dp[n]);
}

// top down
int x, y, z;
int rec(int n, vector<int>& dp) {

    if (n < 0) return -1;
    if (n == 0) return 0;
    if (dp[n] != -1) return dp[n];
    dp[n] = std::max({1 + rec(n - x, dp), 1 + rec(n - y, dp), 1 + rec(n - z, dp)});
    return dp[n];
}

int main() {

    int n; std::cin >> n;
    std::cin >> x >> y >> z;
    vector<int> dp(n + 1, -1);
    int ret = rec(n, dp);
    cout << (ret > 0) ? rec : 0;
}