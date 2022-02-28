#include "../Common.h"


// 求解connected components: BFS (preferred) / DFS
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        if (isConnected.empty())
            return 0;

        int circles= 0;
        int n = isConnected.size();
        vector<int> visited(n, 0);

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(isConnected, visited, i);
                // find circle
                circles++;
            }
        }
        return circles;
    }

private:
    void dfs(vector<vector<int>>& matrix,
             vector<int>& visited,
             int i) {

        // break condition
        if (visited[i])
            return;

        visited[i] = 1;
        for (int j = 0; j < matrix.size(); ++j)
            // if in circle and haven't been visited
            if (matrix[i][j] && !visited[j])
                dfs(matrix, visited, j);
    }
};
