#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
typedef long long ll;
using namespace std;


int main() {

    // INPUT PHASE
    int N; std::cin >> N;
    std::vector<std::pair<ll, ll>> tasks(N);
    for (int i = 0; i < N; i++) std::cin >> tasks[i].second;
    for (int i = 0; i < N; i++) std::cin >> tasks[i].first;
    
    // SORT VECTOR
    std::sort(tasks.begin(), tasks.end());
    std::reverse(tasks.begin(), tasks.end());
    
    std::vector<bool> timetable(N, false);
    ll total_penalty = 0;
    for (int i = 0; i < N; i++) {
        int j = tasks[i].second - 1;
        for (; j >= 0; j--)
            if (!timetable[j]) { timetable[j] = true; break; }
        if (j == -1) total_penalty += tasks[i].first;
    }
    std::cout << total_penalty;
}