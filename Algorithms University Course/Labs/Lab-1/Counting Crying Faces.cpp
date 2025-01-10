#include <vector>
#include <iostream>
#include <algorithm>

bool containsQAQ(std::string& str) {

    int search = 0;
    for (std::size_t i = 0; i < str.length(); i++) {
        if (search == 0 && str[i] == 'Q') search++;
        else if (search == 1 && str[i] == 'A') search++;
        else if (search == 2 && str[i] == 'Q') return true;
    }
    return false;
}

void rec(std::string curr, std::string& str, int index, int search, int& counter) {

    if (search == 3 || containsQAQ(curr)) {
        counter++;
        return;
    }
    if (index == static_cast<int>(str.size())) return;
    rec(curr, str, index + 1, search, counter);
    curr += str[index];
    if (str[index] == 'Q' && (search == 0 || search == 2)) rec(curr, str, index + 1, search + 1, counter);
    else if (str[index] == 'A' && search == 1) rec(curr, str, index + 1, search + 1, counter);
}


int main() {
    std::string str; std::cin >> str; std::string curr("");
    int counter = 0;
    rec(curr, str, 0, 0, counter);
    std::cout << counter;
}