#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

int getVal(int x) {
    int sum = 0;
    while (x != 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main() {
    int x, y;
    cin >> x >> y;
    int mx = INT_MIN;
    int cross = 0;
    for (int i = x; i <= y; i++) {
        int val = getVal(i);
        if (val > mx) {
            cross = i;
            mx = val;
        }
    }
    cout << cross;
    return 0;
}
