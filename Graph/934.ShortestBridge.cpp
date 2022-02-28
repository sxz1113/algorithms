#include "../Common.h"


class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        // use dfs to find island 1
        int m = grid.size(), n = grid[0].size();

        queue<pair<int, int>> gaps;
        bool find = false;

        for (int i = 0; i < m; ++i) {
            if (find)
                break;
            for (int j = 0; j < n; ++j) {
                // find land, begin dfs
                if (grid[i][j] == 1) {
                    dfs(grid, gaps, i, j);
                    find = true;
                    break;
                }
            }
        }

        // bfs
        int x, y;
        int level = 0;
        while (!gaps.empty()){
            ++level;
            int n_points = gaps.size();
            while (n_points--) {
                auto [r, c] = gaps.front();
                gaps.pop();
                for (int k = 1; k < steps.size(); ++k) {
                    x = r + steps[k - 1], y = c + steps[k];
                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        if (grid[x][y] == 2) {
                            continue;
                        }
                        if (grid[x][y] == 1) {
                            return level;
                        }
                        gaps.push({x, y});
                        grid[x][y] = 2;
                    }
                }
            }
        }
        return 0;
    }

private:
    vector<int> steps {-1, 0, 1, 0, -1};
    void dfs(vector<vector<int>>& grid, 
             queue<pair<int, int>>& gaps,
             int i, 
             int j) {
        int m = grid.size(), n = grid[0].size();
        // break condition
        // grid[i][j] == 2 ? visited : not visited
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 2)
            return;

        if (grid[i][j] == 0) {
            gaps.push({i, j});
            return;
        }

        // mark land for island 1
        grid[i][j] = 2;
        for (int k = 0; k < 4; ++k) {
            dfs(grid, gaps, i + steps[k], j + steps[k + 1]);
        }
    }
};