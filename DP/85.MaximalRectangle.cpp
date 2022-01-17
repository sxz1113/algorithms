#include "Common.h"


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        /**
         * @brief subproblem
         * let dp[x][y] := max length of all 1's can achieve at (x, y).
         * must be sequence ends at column y
         * if matrix[x][y] == '0'
         *     dp[x][y] = 0
         * else
         *     dp[x][y] = d[x][y - 1] + 1
         */
        int m = matrix.size();

        if (m == 0) {
            return 0;
        }

        int n = matrix[0].size();

        vector<vector<int>> lengths(m, vector<int>(n, 0));
        int max_size = 0, val, l;

        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < n; ++j) {
                val = matrix[i][j] - '0';
                lengths[i][j] = (val == 0) ? 0 : lengths[i][j - 1] + 1;
                cout << lengths[i][j] << " ";
            }
            cout << endl;
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                l = INT_MAX;
                for (int k = i; k < m; ++k) {
                    l = min(l, lengths[k][j]);
                    if (l == 0) {
                        break;
                    }
                    max_size = max(max_size, l * (k - i + 1));
                }
            }
        }
        return max_size;
    }
};

