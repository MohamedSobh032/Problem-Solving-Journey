#include <iostream>
#include <climits>

int getVal(int x) {
    int sum = 0;
    while (x != 0) { sum += x % 10; x /= 10; }
    return sum;
}

int main() {
    int x, y; std::cin >> x >> y;
    int mx = INT_MIN, cross = 0;
    for (int i = x; i <= y; i++) {
        int val = getVal(i);
        if (val > mx) { cross = i; mx = val; }
    }
    std::cout << cross;
}
