#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n; std::cin >> n;
    std::vector<int> prices(n, 0);
    for (int i = 0; i < n; i++)
        std::cin >> prices[i];
    int money; std::cin >> money;
    
    std::sort(prices.begin(), prices.end());
    int counter = 0;
    for (int i = 0; i < n; i++) {
        if (money >= prices[i]) {
            counter++;
            money -= prices[i];
        } else break;
    }
    cout << counter;
}


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int main() {
    
    int n; std::cin >> n;
    std::vector<int> prices(n, 0);
    for (int i = 0; i < n; i++)
        std::cin >> prices[i];
    int money; std::cin >> money;
    
    priority_queue<pair<int, int>, vector<int>, std::greater<int>> pq;
    // put all the value to be sorted by frequency
    for (const auto& price: prices)
        pq.push(price);
    
    int counter = 0;
    for (int i = 0; i < n; i++) {
        if (money >= pq.top()) {
            counter++;
            money -= pq.top();
            pq.pop();
        } else break;
    }
    cout << counter;
}

