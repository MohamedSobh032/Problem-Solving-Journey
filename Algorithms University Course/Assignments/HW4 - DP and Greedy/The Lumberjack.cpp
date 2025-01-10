#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

int main() {

    int N, M; std::cin >> N; std::cin >> M;
    std::vector<int> cuts(M, 0);
    for (int i = 0; i < M; i++) std::cin >> cuts[i];
    cuts.insert(cuts.begin(), 0);
    cuts.push_back(N);

    std::vector<std::vector<int>> dp(M + 2, std::vector<int>(M + 2, 0));
    for (int i = 2; i <= M + 1; i++) {
        for (int j = 0; j <= M + 1 - i; j++) {
            int temp = j + i;
            dp[j][temp] = INT_MAX;
            for (int k = j + 1; k < temp; k++)
                dp[j][temp] = std::min(dp[j][temp], dp[j][k] + dp[k][temp] + (cuts[temp] - cuts[j]));
        }
    }
    std::cout << dp[0][M + 1];
}
