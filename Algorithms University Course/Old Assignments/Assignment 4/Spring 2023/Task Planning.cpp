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
    for (int i = 0; i < N; i++)
        std::cin >> tasks[i].second;
    for (int i = 0; i < N; i++)
        std::cin >> tasks[i].first;
    // SORT
    std::sort(tasks.rbegin(), tasks.rend());
    
    std::vector<bool> timetable(N + 1, false);
    int total_penalty = 0;
    for (int i = 0; i < (int)tasks.size(); i++) {
        bool found = false;
        for (ll j = tasks[i].second; j >= 1; j--) {
            if (timetable[j] == false) {
                timetable[j] = true;
                found = true;
                break;
            }
        }
        if (!found) total_penalty += tasks[i].first;
    }
    cout << total_penalty;
}
