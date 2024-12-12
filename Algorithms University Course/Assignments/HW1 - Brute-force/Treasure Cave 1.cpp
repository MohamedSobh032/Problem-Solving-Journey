/*
Your team have stumbled upon a cave full of treasures, you have equipment that can hold up to a maximum weight W. The cave has a set of items each with a weight and a value. You can choose to take whichever items under the condition that the sum of weights of the chosen items is not greater than the maximum weight W. You are required to find the maximum total value with weight less than or equal to the given limit W. You are required to answer the question above using brute force implemented using recursion.

Input Format
The first line will contain the limit W.
The second line will contain the number of items N.
The next N lines will contain an item each. Each line will contain two space-separated numbers representing the weight and the value of the item respectively.

Constraints
Each item can be chosen once.
Number of items can be from 0 to 25.
W is between 1 and 10000
Each item weight and value is between 1 and 10000

Output Format
One number indicating the maximum value.
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int rec(int& W, int i, int sum, int currWeight, vector<vector<int>>& v) {

    // Termination
    if (currWeight > W)
        return 0;
    if (currWeight == W)
        return sum;
    if (i == v.size())
        return sum;

    // Recursion
    return max(rec(W, i+1, sum+v[i][1], currWeight+v[i][0], v), rec(W, i+1, sum, currWeight, v));
}

int main() {

    int W, C;
    cin >> W >> C;
    vector<vector<int>> v(C, vector<int>(2));
    for (int i = 0; i < C; i++)
        cin >> v[i][0] >> v[i][1];

    cout << rec(W, 0, 0, 0, v);
    return 0;
}