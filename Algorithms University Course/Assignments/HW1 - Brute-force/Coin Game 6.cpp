#include <vector>
#include <iostream>
#include <algorithm>

bool rec(int& T, int i, int sum, std::vector<int>& v) {

    if (i > static_cast<int>(v.size()) || sum > T) return false;
    if (sum == T) return true;
    return rec(T, i + 1, sum + v[i], v) || rec(T, i + 1, sum, v);
}

int main() {

    int T, C; std::cin >> T >> C; std::vector<int> v(C);
    for (int i = 0; i < C; i++) std::cin >> v[i];
    std::cout << rec(T, 0, 0, v);
}