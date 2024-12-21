#include <cmath>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    
    int M; std::cin >> M;
    std::vector<int> ids_query(M);
    for (int i = 0; i < M; i++)
        std::cin >> ids_query[i];
    
    int N; std::cin >> N;
    std::vector<int> nodes(N);
    for (int i = 0; i < N; i++)
        std::cin >> nodes[i];
    
    std::unordered_map<int, std::vector<int>> nmap;
    int E; std::cin >> E;
    for (int i = 0; i < E; i++) {
        char dir; int p, c; std::cin >> dir >> p >> c;
        nmap[nodes[p]].push_back(nodes[c]);
    }
    
    for (int i = 0; i < M; i++) {
        for (const auto& num: nmap[ids_query[i]])
            std::cout << num << ' ';
        std::cout << '\n';
    }
}
