/**
 * @brief First Solution
 * Time Complexity: O(V + E)
 * Space Complexity: O(V + E)
 * Using adjacency list to represent the graph, and then using DFS to check if there is a cycle in the graph.
 */
class Solution {
public:
    bool dfs(int curr_course, std::unordered_map<int, bool>& isVisited, std::unordered_map<int, std::vector<int>>& nmap) {
        
        if (isVisited[curr_course])
            return false;
        
        if (nmap[curr_course].empty())
            return true;

        isVisited[curr_course] = true;
        for (auto& pre: nmap[curr_course])
            if (!dfs(pre, isVisited, nmap))
                return false;

        isVisited[curr_course] = false;
        nmap[curr_course].clear();
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        std::unordered_map<int, std::vector<int>> nmap;
        for (const auto& pre: prerequisites)
            nmap[pre[0]].push_back(pre[1]);

        std::unordered_map<int, bool> isVisited;
        for (int i = 0; i < numCourses; i++)
            if (!dfs(i, isVisited, nmap))
                return false;
        return true;
    }
};