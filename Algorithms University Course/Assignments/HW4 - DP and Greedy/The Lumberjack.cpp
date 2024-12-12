#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int N, M; std::cin >> N; std::cin >> M;
    vector<int> cuts(M, 0);
    for (int i = 0; i < M; i++)
        std::cin >> cuts[i];
    cuts.insert(cuts.begin(), 0);
    cuts.push_back(N);

    vector<vector<int>> dp(M + 2, vector<int>(M + 2, 0));
    for (int i = 2; i <= M + 1; i++) {
        for (int j = 0; j <= M + 1 - i; j++) {
            int temp = j + i;
            dp[j][temp] = 99999999;
            for (int k = j + 1; k < temp; k++)
                dp[j][temp] = min(dp[j][temp], dp[j][k] + dp[k][temp] + (cuts[temp] - cuts[j]));
        }
    }
     cout << dp[0][M + 1];

}
