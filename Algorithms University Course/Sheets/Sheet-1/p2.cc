/*
2. [Recursion] Write a recursive function to print all 𝑘𝑛 value for a given 
radix 𝑘 and 𝑛. Example: given 𝑘 = 3  and 𝑛 = 3, print “000”, “001”, 
“002”,”010”…,”222”. 
*/

#include <iostream>
#include <string>
using namespace std;

int k = 3;
int n = 3;

void rec(string x) {

    // Termination Condition
    if (x.size() == n) {
        std::cout << x << " ";
        return;
    }

    for (int i = 0; i < k; i++)
        rec(x + to_string(i));

}


int main() {
    rec("");
}