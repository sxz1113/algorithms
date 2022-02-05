#include "../Common.h"


class Solution {
    vector<int> dx {0, 0, 1, -1};
    vector<int> dy {1, -1, 0, 0};
public:
    // dfs
    int numIslandsDFS(vector<vector<char>>& grid) {
        // edge case:
        if (grid.empty())
            return 0;

        int m = grid.size(), n = grid[0].size();
        int n_islands = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                n_islands += grid[i][j] - '0';
                dfs(grid, i, j);
            }
        }
        return n_islands;
    }

    // bfs
    int numIslandsBFS(vector<vector<char>>& grid) {
        // edge case:
        if (grid.empty())
            return 0;

        int m = grid.size(), n = grid[0].size();
        int n_islands = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    n_islands++;
                    bfs(grid, i, j);
                }
            }
        }
        return n_islands;
    }

private:
    void dfs(vector<vector<char>>& grid, int x, int y) {
        int m = grid.size(), n = grid[0].size();
        if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == '0')
            return;

        grid[x][y] = '0';
        for (int i = 0; i < dx.size(); ++i)
            dfs(grid, x + dx[i], y + dy[i]);
    }

    void bfs(vector<vector<char>>& grid, 
             int x,
             int y) {

        queue<pair<int, int>> q;
        pair<int, int> p;
        int rx, ry;
        int m = grid.size(), n = grid[0].size();
        grid[x][y] = '0'; 
        q.push({x, y});

        while (!q.empty()) {
            p = q.front();
            q.pop();
            printf("pop (%d, %d)\n", p.first, p.second);
            for (int i = 0; i < dx.size(); ++i) {
                rx = p.first + dx[i];
                ry = p.second + dy[i];
                if (rx >= 0 && rx < m && ry >= 0 && ry < n && grid[rx][ry] == '1') {
                    grid[rx][ry] = '0';
                    q.push({rx, ry});
                }
            }
        }
    }
};
