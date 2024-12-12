#include <cmath>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

int count2(const vector<int>& trees, const int& D) {
    int count = 0;
    unordered_map<int, int> nmap;
    for (size_t i = 0; i < trees.size(); i++) {
        if (nmap.find(trees[i] - D) != nmap.end())
            count += nmap[trees[i] - D];
        nmap[trees[i]]++;
    }
    return count;
}


int count3(vector<int>& trees, unordered_map<int, vector<int>>& nmap, int D) {

    int count = 0;
    // iterate on all the values
    for (size_t i = 0; i < trees.size(); i++) {   
          if (nmap.find(trees[i] + D) != nmap.end() &&
             nmap.find(trees[i] + 2*D) != nmap.end()) {
              // if the two conditions are met, iterate on the indices of the value
              for (size_t j = 0; j < nmap[trees[i] + D].size(); j++) {
                  // check if the element is after it
                  if (nmap[trees[i] + D][j] > i) {
                      for (size_t k = 0; k < nmap[trees[i] + 2*D].size(); k++) {
                          if (nmap[trees[i] + 2*D][k] > nmap[trees[i] + D][j])
                              count++;
                      }
                  }
              }
              
          }
    }

    return count;
}


int main() {
    
    // input
    int N, D, M;
    std::cin >> N >> D >> M;
    vector<int> trees(N);
    for (int i = 0; i < N; i++)
        std::cin >> trees[i];
    
    int count = 0;
    if (M == 2)
        count = count2(trees, D);
    else {
        unordered_map<int, vector<int>> nmap;
        for (int i = 0; i < N; i++)
            nmap[trees[i]].push_back(i);
        count = count3(trees, nmap, D);
    }
    std::cout << count;
    
    return 0;
}
