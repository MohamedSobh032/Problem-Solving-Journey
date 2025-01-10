#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {

    int n; std::cin >> n;
    std::vector<std::vector<int>> ins(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            std::cin >> ins[i][j];
    
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, INT_MAX));
    for (int i = n - 1; i >= 0; i--) dp[n - 1][i] = ins[n - 1][i];

    for (int i = n - 2; i >= 0; i--)
        for (int j = i; j >= 0; j--)
            dp[i][j] = ins[i][j] + std::min(dp[i + 1][j], dp[i + 1][j + 1]);
    std::cout << dp[0][0];
}
