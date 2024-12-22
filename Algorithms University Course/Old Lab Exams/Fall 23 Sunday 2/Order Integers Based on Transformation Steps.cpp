#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void get_transformation(int x, int& counts) {
    
    // base-case
    if (x == 1) return;
    counts++;
    x = (x % 2 == 0) ? (x / 2) : ((3*x) + 1);
    get_transformation(x, counts);    
}

int main() {
    
    int start, end, target; std::cin >> start >> end >> target;
    int vec_size = end - start + 1;
    std::vector<std::pair<int, int>> vec(vec_size);
    
    for (int i = 0; i < vec_size; i++) {
        int counts = 0;
        get_transformation(i + start, counts);
        vec[i] = std::make_pair(counts, i + start);
    }

    std::sort(vec.begin(), vec.end());
    std::cout << vec[target - 1].second;
}