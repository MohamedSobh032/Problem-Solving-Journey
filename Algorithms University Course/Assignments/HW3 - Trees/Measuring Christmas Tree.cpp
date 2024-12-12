/*
Santa is giving christmas trees with only two lengths X and Y. He needs to make sure that the tree length is exactly X or Y and for doing so he has a measuring tape but it has strange distances, it starts with 0 and ends with L and in the middle it has some numbers that represent distances. To measure distance D with the tape there should be a pair of numbers on the tape V1 and V2 such that V2 - V1 = D. Your task is to determine what is the minimum number of additional distances you need to add to the tape so that they can be used to measure the distances x and y. You are allowed to use unordered_map and unordered_set if needed

Input Format
The first line contains four positive space-separated integers N, L, X, Y — the number of distances on the measuring tape, the length of the measuring tape and the two allowed lengthes of the trees
The second line contains a sequence of n integers a1, a2, ..., an (0 = a1 < a2 < ... < an = l), where ai shows the distance between number i from the origin

Constraints
(2 ≤ n ≤ 10^5, 2 ≤ l ≤ 10^9, 1 ≤ x < y ≤ l)

Output Format
print a single non-negative integer v — the minimum number of distances that you need to add on the tape.
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {

    int N, L, X, Y;
    std::cin >> N >> L >> X >> Y;
    std::vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    // Add all available distances that can be measured in a set
    std::set<int> mastara;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++)
            mastara.insert(a[j] - a[i]);
    }

    // if X and Y can be measured, print 0 and return
    bool searchX = mastara.count(X);
    bool searchY = mastara.count(Y);
    if (searchX && searchY) {
        // do nothing
        cout << 0;
        return 0;
    }

    // if both couldn't be found, get all the possible solutions for X and Y
    // Check if they have solution in common
    // if there is, print 1 and return
    // if did not find any, print 2 and return
    else if (!searchX && !searchY) {
        
        unordered_map<int, bool> nmap;
        // append all possible solutions of X in a hashmap
        for (int i = 0; i < (int)a.size(); i++) {
            if (X + a[i] < L)
                nmap[X + a[i]] = true;
            if (a[i] - X > 0)
                nmap[a[i] - X] = true;
        }

        // iterate on all possible solutions of Y, if there is anyone that exists with X, print 1
        for (int i = 0; i < (int)a.size(); i++) {
            if (nmap[Y + a[i]] == true || nmap[a[i] - Y] == true) {
                cout << 1;
                return 0;
            }
        }
        // else print 2
        cout << 2;
        return 0;
    }

    // if only 1 is not available, print 1 and return
    else {
        cout << 1;
        return 0;
    }
}
