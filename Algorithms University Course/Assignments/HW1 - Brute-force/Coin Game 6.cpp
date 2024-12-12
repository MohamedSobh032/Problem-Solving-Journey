/*
You are playing a game and you are given a collection of coins of size N where each coin has a value in pounds as an array of positive integers A[0...N-1]. You find a mission that requires you to collect exactly a total value of T pounds. Is it possible to take coins from A that sums to exactly T? You are required to answer the question above using non-optimized brute force solution.

Input Format
The first line will contain T.
The second line will contain N, denoting the number of integers in the array A.
Each of the next N lines will contain an integer to build the array A.

Constraints
Each coin A[i] can be taken once.
Range of N is from 1 to 25.
T value can be 0.

Output Format
1 if you can choose coins that sums to exactly T and 0 if you cannot.
*/
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool rec(int& T, int i, int sum, vector<int>& v) {
    
    // Termination
    if (i > v.size())
        return false;
    if (sum > T)
        return false;
    if (sum == T)
        return true;
    
    // Recursion
    return rec(T, i + 1, sum + v[i], v) || rec(T, i + 1, sum, v);
}

int main() {

    int T, C;
    cin >> T >> C;
    vector<int> v(C);
    for (int i = 0; i < C; i++)
        cin >> v[i];

    if (rec(T, 0, 0, v))
        cout << 1;
    else
        cout << 0;
    return 0;
}
