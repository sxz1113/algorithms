#include "../Common.h"


class Solution {
public:
    // int maxAreaOfIsland(vector<vector<int>>& grid) {
    //     // edge case
    //     if (grid.empty() || grid[0].empty())
    //         return 0;

    //     int m = grid.size(),
    //         n = grid[0].size();
    //     int max_area = 0;
    //     for (int i = 0; i < m; ++i) {
    //         for (int j = 0; j < n; ++j) {
    //             // find new land
    //             if (grid[i][j]) {
    //                 max_area = max(max_area, dfs(grid, i, j));
    //             }
    //         }
    //     }

    //     return max_area;
    // }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;

        int m = grid.size(), n = grid[0].size();
        // global max area, and local area after a land is identified
        int max_area = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    max_area = max(max_area, dfsByStack(grid, i, j));
                }
            }
        }

        return max_area;
    }

private:
    const vector<int> steps {0, 1, 0, -1, 0};

    bool isIsland(vector<vector<int>>& grid, 
                  int i, 
                  int j) {
        int m = grid.size(),
            n = grid[0].size();

        return (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) ? false : true;
    }

    int dfs(vector<vector<int>>& grid,
            int i,
            int j) {
        if (!isIsland(grid, i, j)) return 0;

        int area = 1;
        grid[i][j] = 0;
        // find all neighboring land
        for (int k = 1; k < steps.size(); ++k)
            area += dfs(grid, i + steps[k], j + steps[k - 1]);

        return area;
    }

    int dfsByStack(vector<vector<int>>& grid, 
                   int i,
                   int j) {
        // stack for backtrakcing
        stack<pair<int, int>> stk;
        int rx, ry, area = 1;
        grid[i][j] = 0;
        stk.push({i, j});
        printf("(%d, %d) => stack\n", i, j);
        while (!stk.empty()) {
            auto [x, y] = stk.top();
            printf("stack => (%d, %d)\n", x, y);
            stk.pop();
            for (int k = 1; k < steps.size(); ++k) {
                rx = x + steps[k - 1];
                ry = y + steps[k];
                if (isIsland(grid, rx, ry)) {
                    area++;
                    grid[rx][ry] = 0;
                    stk.push({rx, ry});
                    printf("(%d, %d) => stack\n", rx, ry);
                }
            }
        }
        printf("local area = %d\n", area);
        return area;
    }
};
