#include <cmath>
#include <climits>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int n; std::cin >> n;
    vector<vector<int>> ins(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            std::cin >> ins[i][j];
    
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    for (int i = n - 1; i >= 0; i--)
        dp[n-1][i] = ins[n-1][i];
    for (int i = n - 2; i >= 0; i--)
        for (int j = i; j >= 0; j--)
            dp[i][j] = ins[i][j] + std::min(dp[i+1][j], dp[i+1][j+1]);
    cout << dp[0][0];
}
