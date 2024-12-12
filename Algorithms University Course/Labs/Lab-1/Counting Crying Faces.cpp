#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool containsQAQ(string& str) {
    int search = 0;
    for (int i = 0; i < str.length(); i++) {
        if (search == 0 && str[i] == 'Q')
            search++;
        else if (search == 1 && str[i] == 'A')
            search++;
        else if (search == 2 && str[i] == 'Q')
            return true;
    }
    return false;
}

void rec(string curr, string& str, int index, int search, int& counter) {

    if (search == 3) {
        counter++;
        return;
    }
    if (containsQAQ(curr)) {
        counter++;
        return;
    }
    if (index == str.length())
        return;
    rec(curr, str, index + 1, search, counter);
    curr = curr + str[index];
    if (str[index] == 'Q' && (search == 0 || search == 2))
        rec(curr, str, index + 1, search + 1, counter);
    else if (str[index] == 'A' && search == 1)
        rec(curr, str, index + 1, search + 1, counter);
}


int main() {
    string str; std::cin >> str;
    string curr = "";
    int counter = 0;
    rec(curr, str, 0, 0, counter);
    cout << counter;
    return 0;
}