#include <iostream>
#include <cmath>
using namespace std;

long long binomialCoefficient(int a, int b) {
    
    if (b > a) return 0;
    if (b == 0 || b == a) return 1;
    long long res = 1;
    for (int i = 1; i <= b; i++) {
        res *= a--;
        res /= i;
    }
    return res;
}

int main() {
    int n; std::cin >> n;
    std::cout << binomialCoefficient(n + 4, 4) << std::endl;
}
