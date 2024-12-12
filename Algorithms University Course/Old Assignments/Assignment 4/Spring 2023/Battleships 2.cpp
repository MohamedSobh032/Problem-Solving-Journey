#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

unordered_map<int, pair<int, int>> memo;

pair<int, int> rec(const std::vector<int>& weapons, int ship) {

    // memoization
    if (memo.find(ship) != memo.end())
        return memo[ship];

    // basecase
    if (ship < 0)
        return { 0, 0 };

    int min_cuts = INT_MAX;
    int min_rem = INT_MAX;
    bool flag = false;

    // recursion
    for (size_t i = 0; i < weapons.size(); i++) {
        if (weapons[i] > ship)
            continue;
        if (weapons[i] == 0)
            continue;
        flag = true;
        auto result = rec(weapons, ship - weapons[i]);
        int current_cuts = result.first + 1;
        int current_rem = result.second;

        if (current_rem < min_rem || (current_rem == min_rem && current_cuts < min_cuts)) {
            min_rem = current_rem;
            min_cuts = current_cuts;
        }
    }
    
    if (flag == true) {
        memo[ship] = { min_cuts, min_rem };
        return { min_cuts, min_rem };
    } else {
        memo[ship] = { 0, ship };
        return { 0, ship };
    }
}

int main() {

    int M; std::cin >> M;
    std::vector<int> ships(M, 0);
    for (int i = 0; i < M; i++)
        std::cin >> ships[i];
    int N; std::cin >> N;
    std::vector<int> weapons(N, 0);
    for (int i = 0; i < N; i++)
        std::cin >> weapons[i];
    std::sort(weapons.rbegin(), weapons.rend());

    for (int i = 0; i < M; i++) {
        auto result = rec(weapons, ships[i]);
        cout << result.second << ' ' << result.first << endl;
    }
}