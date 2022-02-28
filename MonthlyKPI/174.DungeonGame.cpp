#include "../Common.h"


class Solution {
public:
    // memorization
    int calculateMinimumHPMemo(vector<vector<int>>& dungeon) {
        int m = dungeon.size(),
            n = dungeon[0].size();

        vector<vector<int>> cost(m, vector<int>(n, 1e9));
        return helper(dungeon, cost, 0, 0);
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(),
            n = dungeon[0].size();

        vector<vector<int>> cost(m + 1, vector<int>(n + 1, 1e9));
        // init end point
        cost[m][n - 1] = 1;
        cost[m - 1][n] = 1;

        int cur_cost;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                cur_cost = min(cost[i + 1][j], cost[i][j + 1]) - dungeon[i][j];
                cost[i][j] = cur_cost > 0 ? cur_cost : 1;
            }
        }
        return cost[0][0];
    }

private:
    int helper(vector<vector<int>>& grid, 
               vector<vector<int>>& cost, 
               int i, 
               int j) {
        // break condition
        int m = grid.size(), 
            n = grid[0].size();

        if (i >= m || j >= n)
            return 1e9;

        // if calculated / cached, return val
        if (cost[i][j] != 1e9)
            return cost[i][j];

        // base case, reach bottom right corner
        if (i == m - 1 && j == n - 1)
            return (grid[i][j] <= 0) ? 1 - grid[i][j]: 1;

        int cur_cost = min(helper(grid, cost, i + 1, j),
                           helper(grid, cost, i, j + 1)) 
                       - grid[i][j];

        cost[i][j] = cur_cost > 0 ? cur_cost : 1;
        return cost[i][j];
    }
};