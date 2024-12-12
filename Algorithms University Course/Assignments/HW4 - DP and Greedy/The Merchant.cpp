#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {

    int M, A, B; std::cin >> M >> A >> B;
    int l_rem = M;
    int l_a = INT_MAX;
    int l_b = INT_MAX;
    int greed = M / B;
    for (int i = greed; i >= 0; i--) {
        int curr_rem = M - (i * B);
        // for this remainder, get the number of A's we can fit
        int A_used = curr_rem / A;
        curr_rem = curr_rem % A;
        if (curr_rem < l_rem) {
            l_rem = curr_rem;
            l_a = A_used;
            l_b = i;
        } else if (curr_rem == l_rem) {
            if (A_used < l_a) {
                l_rem = curr_rem;
                l_a = A_used;
                l_b = i;
            } else if (A_used == l_a) {
                if (i < l_b) {
                    l_rem = curr_rem;
                    l_a = A_used;
                    l_b = i;
                }
            }
        }
    }
    cout << l_a << ' ' << l_b << ' ' << l_rem;
}
