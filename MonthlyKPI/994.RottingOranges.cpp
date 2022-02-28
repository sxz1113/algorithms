#include "../Common.h"


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;

        int m = grid.size(),
            n = grid[0].size(),
            ts = 0;

        queue<pair<int, int>> q;
        const vector<int> directions {0, 1, 0, -1, 0};
        int fresh = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        while (fresh > 0 && !q.empty()) {
            int rotten = q.size();
            while (rotten--) {
                pair r = q.front();
                q.pop();
                for (int k = 1; k < directions.size(); ++k) {
                    int rx = r.first + directions[k - 1], 
                        ry = r.second + directions[k];
                    if (rx >= 0 && rx < m && ry >= 0 && ry < n && grid[rx][ry] == 1) {
                        grid[rx][ry] = 2;
                        q.push({rx, ry});
                        fresh--;
                    }
                }
            }
            ts++;
        }

        return fresh > 0 ? -1 : ts;
    }
};