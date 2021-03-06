#include "Common.h"


class Solution {
public:
    int minDistance(string word1, string word2) {
        /**
         * @brief subproblem: 
         * let min distance d(i, j) := minDistance(word1[0, ..., i], word2[0, ..., j])
         * d(i, j) = min(d(i - 1, j) + 1,             delete last char in word1
         *               d(i, j - 1) + 1,             insert last char in word2
         *               d(i - 1, j - 1) + diff)  replace last char <-> word1 & word2 if not equal
         */

        int m = word1.size(),
            n = word2.size();

        // init solution matrix, add padding
        vector<vector<int>> d(m + 1, vector<int>(n + 1, 0));
        for (size_t i = 0; i <= m; ++i)
            d[i][0] = i;

        for (size_t j = 0; j <= n; ++j)
            d[0][j] = j;

        for (size_t i = 1; i <= m; ++i) {
            for (size_t j = 1; j <= n; ++j) {
                int c = (word1[i - 1] == word2[j - 1]) ? 0 : 1;
                d[i][j] = min(d[i - 1][j - 1] + c,
                              min(d[i - 1][j], d[i][j - 1]) + 1);
            }
        }

        return d[m][n];
    }
};
