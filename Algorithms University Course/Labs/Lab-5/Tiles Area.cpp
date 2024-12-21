#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    
    // input
    int n; std::cin >> n;
    
    // init
    std::vector<long long> dp(n + 1, INT_MAX);
    dp[0] = 0;
    
    // solve
    for (int i = 1; i <= n; i++)
        for (int j = 1; j * j <= i; j++)
            dp[i] = std::min(dp[i], dp[i - j * j] + 1);
    
    std::cout << dp[n];
}