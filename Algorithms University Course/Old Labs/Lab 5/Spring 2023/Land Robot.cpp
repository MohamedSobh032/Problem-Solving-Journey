#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M; std::cin >> N >> M;
    
    std::vector<std::vector<long long>> map(N, std::vector<long long>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            std::cin >> map[i][j];
    
    std::vector<std::vector<long long>> dp(N, std::vector<long long>(M, 0));
    dp[N - 1][M - 1] = map[N - 1][M - 1];

    for (int j = M - 2; j >= 0; j--)
        dp[N - 1][j] = map[N - 1][j] + dp[N - 1][j + 1];
    
    for (int i = N - 2; i >= 0; i--)
        dp[i][M - 1] = map[i][M - 1] + dp[i + 1][M - 1];
    
    for (int i = N - 2; i >= 0; i--)
        for (int j = M - 2; j >= 0; j--)
            dp[i][j] = map[i][j] + max({dp[i + 1][j], dp[i][j + 1], dp[i + 1][j + 1]});
    
    cout << dp[0][0] << endl;
}
