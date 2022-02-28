#include "../Common.h"


class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // edge case
        if (heights.empty())
            return {};

        int m = heights.size(), 
            n = heights[0].size();

        vector<vector<bool>> reach_pa(m, vector(n, false));
        vector<vector<bool>> reach_at(m, vector(n, false));
        vector<vector<int>> res;

        // vertical scan
        for (int i = 0; i < m; ++i) {
            dfs(heights, reach_pa, i, 0);
            dfs(heights, reach_at, i, n - 1);
        }

        // horizontal scan
        for (int j = 0; j < n; ++j) {
            dfs(heights, reach_pa, 0, j);
            dfs(heights, reach_at, m - 1, j);
        }

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (reach_pa[i][j] && reach_at[i][j])
                    res.push_back(vector<int>{i, j});

        return res;
    }

private:
    const vector<int> steps {0, 1, 0, -1, 0};
    void dfs(const vector<vector<int>>& grid,
             vector<vector<bool>>& reachable,
             int i,
             int j) {
        // if visited
        if (reachable[i][j])
            return;

        reachable[i][j] = true;
        int m = grid.size(),
            n = grid[0].size(),
            x,
            y;
 
        for (int k = 1; k < steps.size(); ++k) {
            x = i + steps[k - 1];
            y = j + steps[k];
            if (x >= 0 && x < m && 
                y >= 0 && y < n && 
                grid[i][j] <= grid[x][y])
                dfs(grid, reachable, x, y);
        }
    }
};
