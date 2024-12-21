#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    // INPUT
    int N; std::cin >> N;
    std::vector<int> nums(N);
    for (int i = 0; i < N; i++)
        std::cin >> nums[i];
    
    // UN-HANDLED CASE
    if (N == 1) {
        std::cout << nums[0];
        return 0;
    }
    
    // SOLVE
    std::vector<int> dp(N, 0);
    dp[0] = nums[0]; dp[1] = nums[1];
    for (int i = 2; i < N; i++)
        dp[i] = std::min(dp[i - 2], dp[i - 1]) + nums[i];
    
    // OUTPUT
    cout << std::min(dp[N - 1], dp[N - 2]);
}
