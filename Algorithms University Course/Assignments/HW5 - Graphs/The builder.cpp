#include <iostream>
#include <vector>
#include <set>

int main() {
    
    ///////////////////////////////////////////// INPUT PHASE /////////////////////////////////////////////
    int N; std::cin >> N;
            // ADJACENY LIST
    std::vector<std::vector<int>> graph(N);
    std::vector<int> in_degree(N, 0);
            // GRAPH BUILD, IN_DEGREE BUILD
    for (int i = 0; i < N; i++) {
        int g1, g2; std::cin >> g1 >> g2;
        if (g1 != -1) { graph[g1].push_back(i); in_degree[i]++; }
        if (g2 != -1) { graph[g2].push_back(i); in_degree[i]++; }
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    
    std::vector<int> ans;
          // SORT DESCENDINGLY
          // FIRSTLY, ADD ALL ELEMENTS WITH NO DEPENDENCY (START POINT)
    std::set<int, std::greater<int>> available;
    for (int i = 0; i < N; i++)
        if (in_degree[i] == 0)
            available.insert(i);
    
    //////////////////////////////////////////// TOPO SORTING /////////////////////////////////////////////
    while (!available.empty()) {
        // LEAST DEPENDENCY
        int curr = *available.begin();
        available.erase(available.begin());
        ans.push_back(curr);
        
        for (const auto& dependency: graph[curr]) {
            in_degree[dependency]--;
            if (in_degree[dependency] == 0)
                available.insert(dependency);
        }
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    
    // OUTPUT
    for (int i = 0; i < N; i++) std::cout << ans[i] << ' ';
}