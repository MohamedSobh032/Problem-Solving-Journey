#include <iostream>
#include <vector>
#include <algorithm>

struct Edge { int from, to, cost; };

// Find function for disjoint set
// the point is to be used for path compression
int find(std::vector<int>& parent, int x) {
    
    // Check if the current node is its own parent
    // If not, recursively find the parent of the parent (path compression)
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]);
    
    // Return the root
    return parent[x];
}

// Union function for disjoint set
// will be used for merging two sets
bool unite(std::vector<int>& parent, std::vector<int>& rank, int x, int y) {
    
    // Firstly, find the roots of both sets
    int px = find(parent, x);
    int py = find(parent, y);
    
    // If both nodes are already in the same set, no need to unite
    if (px == py) return false;
    
    // Union by rank: attach the tree with the smaller rank to the tree with the larger rank
    if (rank[px] < rank[py]) std::swap(px, py);
    parent[py] = px;        // Make the parent of py be px (union operation)
    if (rank[px] == rank[py]) rank[px]++; // If both trees have the same rank, increment the rank of the new root
    
    return true;
}


int main() {
    
    // INPUT
    int n, m, a; std::cin >> n >> m >> a;
    std::vector<Edge> edges(m);
    for (int i = 0; i < m; i++) std::cin >> edges[i].from >> edges[i].to >> edges[i].cost;
    
    // Sort edges in ascending order based on their cost
    // Sort by specific condition --> lambda function
    std::sort(edges.begin(), edges.end(), 
        [](const Edge& e1, const Edge& e2) { 
            return e1.cost < e2.cost; 
        });
    
    std::vector<int> parent(n + 1);
    std::vector<int> rank(n + 1, 0);
    for (int i = 0; i <= n; i++) parent[i] = i;
    
    long long total_cost = 0;
    int components = n;
    
    for (const Edge& e : edges) {
        // If the cost of the current edge is greater than or equal to the cost of building
        // a new water treatment plant, break
        // (No need to connect this edge if it's more expensive than building a plant)
        if (e.cost >= a) break;
        
        // Try to unite the two components (from and to of the edge)
        if (unite(parent, rank, e.from, e.to)) {
            total_cost += e.cost;   // If the union is successful, add the edge's cost to the total cost
            components--;           // Reduce the number of components since we've connected two components
        }
    }
    
    // Add the cost of building water treatment plants for each remaining component
    total_cost += (long long)components * a;
    std::cout << total_cost << ' ' << components;
}
