#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, k;

void rec(int i, bool& flag, int count, std::vector<int>& primes) {
    
    if (i == n) return;
    
    if (count >= k) flag = 1;
    
    bool isprime = 1;
    for (int j = 2; j < i / 2; j++) {
        if (i % j == 0) {
            isprime = 0;
            break;
        }
    }
    if (isprime) {
        for (int j = 0; j < (int)primes.size() - 1; j++) {
            if (i == primes[j] + primes[j+1] + 1) {
                count++; break;
            }
        }
    }
    
    if (isprime) primes.push_back(i);
    rec(i + 1, flag, count, primes);
}

int main() {
    
    std::cin >> n >> k;
    std::vector<int> primes;
    primes.push_back(2);
    primes.push_back(3);
    
    bool flag = 0;
    rec(4, flag, 0, primes);
    std::cout << flag;
}
