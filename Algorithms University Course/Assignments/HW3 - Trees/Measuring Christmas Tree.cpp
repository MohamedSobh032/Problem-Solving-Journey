#include <vector>
#include <iostream>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {

    int N, L, X, Y; std::cin >> N >> L >> X >> Y;
    std::vector<int> a(N);
    for (int i = 0; i < N; i++) std::cin >> a[i];

    // Add all available distances that can be measured in a set
    std::set<int> mastara;
    for (int i = 0; i < N - 1; i++)
        for (int j = i + 1; j < N; j++)
            mastara.insert(a[j] - a[i]);

    // if X and Y can be measured, print 0 and return
    bool searchX = mastara.count(X), searchY = mastara.count(Y);
    if (searchX && searchY)
        std::cout << 0;

    // if both couldn't be found, get all the possible solutions for X and Y
    // Check if they have solution in common
    // if there is, print 1 and return
    // if did not find any, print 2 and return
    else if (!searchX && !searchY) {
        
        std::unordered_map<int, bool> nmap;
        // append all possible solutions of X in a hashmap
        for (int i = 0; i < (int)a.size(); i++) {
            if (X + a[i] < L) nmap[X + a[i]] = true;
            if (a[i] - X > 0) nmap[a[i] - X] = true;
        }

        // iterate on all possible solutions of Y, if there is anyone that exists with X, print 1
        for (int i = 0; i < (int)a.size(); i++) {
            if (nmap[Y + a[i]] == true || nmap[a[i] - Y] == true) {
                std::cout << 1;
                return 0;
            }
        }
        // else print 2
        std::cout << 2;
    }

    // if only 1 is not available, print 1 and return
    else std::cout << 1;

}
