#include "Common.h"


// 标签：dp，分组
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        /**
         * @brief subproblem
         * Let T[i] := minimum height of the bookshelf after placing ith book
         * T[i] = min(T[j - 1] + a[j][1]), where 0 < j <= i
         */

        int n = books.size(), h, w;
        vector<int> dp(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            h = 0;
            w = 0;
            // place book on the new shelf
            dp[i + 1] = dp[i] + books[i][1];
            for (int j = i; j >= 0; --j) {
                if ((w += books[j][0]) > shelfWidth)
                    break;
                h = max(h, books[j][1]);
                dp[i + 1] = min(dp[j] + h, dp[i + 1]);
            }
        }
        return dp[n];
    }
};