#include <vector>
#include <iostream>
#include <algorithm>

int main() {

    int n; std::cin >> n;
    std::vector<std::pair<long long, long long>> blns(n);
    for (int i = 0; i < n; i++) {
        int score, next; std::cin >> score >> next;
        blns[i] = std::make_pair(score, next);
    }
    
    std::vector<long long> dp(n, 0); dp[n - 1] = blns[n - 1].first;
    for (int i = n - 2; i >= 0; i--)
        dp[i] = std::max(dp[i + 1], blns[i].first + (i + blns[i].second + 1 <= n - 1 ? dp[i + blns[i].second + 1] : 0));
    std::cout << dp[0];
}
