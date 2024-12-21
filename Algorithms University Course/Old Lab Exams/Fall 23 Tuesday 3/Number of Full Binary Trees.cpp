#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n; std::cin >> n;
    std::vector<int> dp(n + 1, 0); dp[1] = 1;
    for (int i = 3; i <= n; i += 2)
        for (int j = 1; j < i; j += 2)
            dp[i] += dp[j] * dp[i - 1 - j];
    std::cout << dp[n];
}