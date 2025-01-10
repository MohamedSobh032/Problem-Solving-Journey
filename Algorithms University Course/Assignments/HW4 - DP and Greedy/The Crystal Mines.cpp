#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <unordered_map>

std::unordered_map<int, std::pair<int, int>> memo;

std::pair<int, int> rec(const std::vector<int>& cutters, int mine) {

    if (memo.find(mine) != memo.end()) return memo[mine];
    if (mine < 0) return { 0, 0 };

    int min_cuts = INT_MAX, min_rem = INT_MAX;
    bool flag = false;

    for (size_t i = 0; i < cutters.size(); i++) {
        if (cutters[i] > mine || cutters[i] == 0) continue;
        flag = true;
        auto result = rec(cutters, mine - cutters[i]);
        int current_cuts = result.first + 1;
        int current_rem = result.second;
        if (current_rem < min_rem || (current_rem == min_rem && current_cuts < min_cuts)) {
            min_rem = current_rem;
            min_cuts = current_cuts;
        }
    }

    return memo[mine] = flag ? std::make_pair(min_cuts, min_rem) : std::make_pair(0, mine);
}

int main() {

    int M; std::cin >> M; std::vector<int> mines(M, 0);
    for (int i = 0; i < M; i++) std::cin >> mines[i];
    
    int N; std::cin >> N;
    std::vector<int> cutters(N, 0);
    for (int i = 0; i < N; i++) std::cin >> cutters[i];
    std::sort(cutters.rbegin(), cutters.rend());

    for (int i = 0; i < M; i++) {
        auto result = rec(cutters, mines[i]);
        std::cout << result.second << ' ' << result.first << std::endl;
    }
}