#include <vector>
#include <iostream>
#include <algorithm>

int rec(int& W, int i, int sum, int currWeight, const std::vector<std::vector<int>>& v) {

    if (currWeight > W) return 0;
    if (currWeight == W || i == static_cast<int>(v.size())) return sum;
    return std::max(rec(W, i + 1, sum + v[i][1], currWeight + v[i][0], v), rec(W, i + 1, sum, currWeight, v));
}

int main() {

    int W, C; std::cin >> W >> C;
    std::vector<std::vector<int>> v(C, std::vector<int>(2));
    for (int i = 0; i < C; i++) std::cin >> v[i][0] >> v[i][1];
    std::cout << rec(W, 0, 0, 0, v);
}