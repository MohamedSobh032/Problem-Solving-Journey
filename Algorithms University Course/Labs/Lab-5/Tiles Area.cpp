#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>

int main() {

    int n; std::cin >> n;
    std::vector<long long> dp(n + 1, INT_MAX); dp[0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j * j <= i; j++)
            dp[i] = std::min(dp[i], dp[i - j * j] + 1);
    std::cout << dp[n];
}