#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int N; std::cin >> N;
    std::vector<int> dp(N + 1, 0);

    dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        if (i < 10)
            dp[i] = 1;
        else {
            std::string i_str = std::to_string(i);
            int greatest = 0;
            for (const auto& ch: i_str)
                greatest = std::max(greatest, ch - '0');
            dp[i] = 1 + dp[i - greatest];
        }
    }
    cout << dp[N];
}
