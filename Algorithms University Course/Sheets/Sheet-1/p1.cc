/*
1. [Recursion] Write a recursive function to print all 2𝑛 value for a given 
   Example: given 𝑛 = 3, print “000”, “001”, “010”,…,”111”. 
a. Trace your code and draw the recursion tree for 𝑛 = 3. In each 
node of the recursion tree, state the values of all variables  
b. Draw the contents of the variables placed in the stack and the 
heap during the execution of the function till printing the first two 
values; “000” and “001”.
*/

#include <iostream>
#include <string>
using namespace std;

void rec(int n, string x) {

    // Termination Condition
    if (n == 0) {
        std::cout << x << " ";
        return;
    }
    // Recursion
    rec(n - 1, x + '0');
    rec(n - 1, x + '1');
}


int main() {
    rec(3, "");
}