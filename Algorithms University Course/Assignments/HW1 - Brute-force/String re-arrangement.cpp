/*
You will be given N strings containing lower case English letters. In one move you can choose a string i and move the first letter from the start of the string to the end of the string. For example, if he has the string "abcdef", in one move he can transform it into the string "bcdefa".
What is the minimum number of moves you need to make the strings identical if possible

Input Format
The first line contains integer n — the number of strings.
This is followed by n lines which contain a string each. Lengths of strings are equal.

Constraints
(1 ≤ n ≤ 50) Lengths of each string is positive and don't exceed 50.

Output Format
Print the minimal number of moves you need in order to make all the strings identical or print  - 1 if there is no solution.
*/
#include <cmath>
#include <climits>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

bool areEqual(vector<string>& strs) {
    for (size_t i = 1; i < strs.size(); i++) {
        if (strs[i].compare(strs[i - 1]))
            return false;
    }
    return true;
}

int cov(vector<string>& x) {

    // el hashmap de hnst5dmha 3shan n3ed
    unordered_map<string, int> hmap;
    for (int i = 0; i < x.size(); i++) {
        unordered_map<string, bool> innermap; 
        for (int j = 0; j < x[0].size(); j++) {
            if (innermap[x[i]] == false) {
                innermap[x[i]] = true;
                hmap[x[i]] += j;
                std::rotate(x[i].begin(), x[i].begin() + 1, x[i].end());
            }
        }
    }
    int minno = INT_MAX;
    for (const auto& it : hmap)
        minno = min(minno, it.second);
    return minno;
}

int main() {

    int c; cin >> c;
    vector<string> x(c);
    for (int i = 0; i < c; i++)
        cin >> x[i];

    if (areEqual(x)) {
        cout << 0;
        return 0;
    }

    int out = cov(x);
    if (out != 0)
        cout << out;
    else
        cout << -1;
    return 0;
}
