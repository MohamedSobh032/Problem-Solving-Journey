#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    int N; std::cin >> N;
    std::vector<int> inputs(N, 0);
    std::vector<int> dp(N, 0);
    for (int i = 0; i < N; i++)
        std::cin >> inputs[i];
    
    int n1 = 0;
    int n2 = 0;
    for (int i = 0; i < N; i++) {
        int temp = std::max(n1, n2 + inputs[i]);
        n2 = n1; n1 = temp;
    }
    std::cout << n1;
}
