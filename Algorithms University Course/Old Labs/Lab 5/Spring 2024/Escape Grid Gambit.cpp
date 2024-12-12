#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

long long dfs(const vector<pair<int, int>>& moves, vector<vector<vector<long long>>>& dp,
              int x, int y, const int& N, int K) {

    if (K < 0)
        return 0;
    if (x < 0 || y < 0 || x >= N || y >= N)
        return 1;
    if (dp[x][y][K] != -1)
        return dp[x][y][K];

    long long sum = 0;
    for (size_t i = 0; i < moves.size(); i++)
        sum += dfs(moves, dp, x + moves[i].first, y + moves[i].second, N, K - 1);
    
    dp[x][y][K] = sum;
    return sum;
}

int main() {
    
    int N, K, R, x, y;
    std::cin >> N >> K >> R >> x >> y;
    std::vector<std::pair<int, int>> moves(R);
    for (int i = 0; i < R; i++) {
        int dx, dy;
        std::cin >> dx >> dy;
        moves[i].first = dx;
        moves[i].second = dy;
    }
    
    vector<vector<vector<long long>>> dp(N, vector<vector<long long>>(N, vector<long long>(K + 1, -1)));
    cout << dfs(moves, dp, x, y, N, K);
    
    return 0;
}
