#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    int N, K;
    std::cin >> N >> K;

    std::vector<std::vector<long long>> dp(N + 1, std::vector<long long>(K + 1, 0));
    dp[0][0] = 1;

    for (int n = 1; n <= N; n++)
        for (int k = 1; k <= K; k++)
            dp[n][k] = dp[n-1][k-1] + k * dp[n-1][k];
    
    cout << dp[N][K];
    
    return 0;
}