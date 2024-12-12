/*
4. [Brute-force] A child is running up a staircase with n steps and can 
hop either 1 step, 2 steps, or 3 steps at a time. Implement a method 
to count how many possible ways the child can run up the stairs. 
*/

#include <iostream>
#include <vector>
using namespace std;

int counter(int stairs) {
    
    if (stairs < 0)
        return 0;

    if (stairs == 0)
        return 1;

    return counter(stairs - 1) + counter(stairs - 2) + counter(stairs - 3);
}

int main() {
    cout << counter(4) << endl;
}