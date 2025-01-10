#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <climits>

bool areEqual(std::vector<std::string>& strs) {

    for (std::size_t i = 1; i < strs.size(); i++)
        if (strs[i].compare(strs[i - 1]))
            return false;
    return true;
}

int cov(std::vector<std::string>& x) {

    std::unordered_map<std::string, int> hmap;
    for (std::size_t i = 0; i < x.size(); i++) {
        std::unordered_map<std::string, bool> innermap; 
        for (std::size_t j = 0; j < x[0].size(); j++) {
            if (!innermap[x[i]]) {
                innermap[x[i]] = true; hmap[x[i]] += j;
                std::rotate(x[i].begin(), x[i].begin() + 1, x[i].end());
            }
        }
    }
    int minno = INT_MAX;
    for (const auto& it : hmap) minno = std::min(minno, it.second);
    return minno;
}

int main() {

    int c; std::cin >> c;
    std::vector<std::string> x(c);
    for (int i = 0; i < c; i++) std::cin >> x[i];

    if (areEqual(x)) {
        std::cout << 0;
        return 0;
    }

    int out = cov(x);
    if (out != 0) std::cout << out;
    else std::cout << -1;
}
