#include "Common.h"


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        /**
         * @brief subproblem: 
         * let dp[x][y] := max size can achieve at (x, y) as bottom right point
         * if matrix[x][y] == 0
         *     dp[x][y] = 0 
         * else
         *     dp[x][y] = min(dp[x - 1][y], 
         *                    dp[x][y - 1],
         *                    dp[x - 1][y - 1]) + 1
         */
        if (matrix.empty()) {
            return 0;
        }

        int m = matrix.size(), 
            n = matrix[0].size();

        vector<vector<int>> sizes(m, vector<int>(n, 0));
        int max_size = 0;
        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < n; ++j) {
                sizes[i][j] = matrix[i][j] - '0';

                // if matrix[i][j] == 0, dp[i][j] = 0
                if (!sizes[i][j]) {
                    continue;
                }

                // check boundary
                if (!(i == 0 || j == 0)) {
                    sizes[i][j] = min(min(sizes[i - 1][j], sizes[i][j - 1]), 
                                      sizes[i - 1][j - 1]) + 1;
                }
                max_size = max(max_size, sizes[i][j] * sizes[i][j]);
                cout << sizes[i][j] << " ";
            }
            cout << endl;
        }

        return max_size;
    }
};
