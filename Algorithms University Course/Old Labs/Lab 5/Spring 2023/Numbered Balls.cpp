// top down
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int T, N; std::cin >> T >> N;
    std::vector<long long> balls(N, 0);
    for (int i = 0; i < N; i++)
        std::cin >> balls[i];

    std::vector<long long> dp(T + 1, T + 1);
    dp[0] = 0;
    for (long long i = 1; i < T + 1; i++) {
        for (const auto& ball : balls) {
            if (ball > i)
                continue;
            dp[i] = std::min(dp[i], 1 + dp[i - ball]);
        }
    }
    if (dp[T] == T + 1)
        cout << "no solution";
    else
        cout << dp[T];
}
