#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;


int main() {
    
    // INPUT
    int N; std::cin >> N;
    std::vector<std::vector<int>> grid(N, std::vector<int>(N, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            std::cin >> grid[i][j];

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int minimum = INT_MAX;
            for (int k = 0; k < N; k++) {
                if (j != k && grid[i - 1][k] <= minimum)
                    minimum = grid[i - 1][k];
            }
            grid[i][j] += minimum;
        }
    }
    
    int minimum = INT_MAX;
    for (int i = 0; i < N; i++)
        minimum = std::min(minimum, grid[N-1][i]);
    std::cout << minimum;
}
