#include "Common.h"


class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        /**
         * @brief subproblem:
         * let dp[i][j] := the # of distinct sequences a1, a2, ..., aj ends with j
         * i - length of the sequence
         * 
         * for j = 1 ... 6, dp[1][j] = 1
         * (only 1 distinct seq possible when the length is 1)
         * 
         * dp[i][j] = sum(dp[i - 1])
         * k = i - rollMax[j]
         * if k == 1, just exceed the max allowed length by 1
         *     dp[i][j] -= 1
         * if k > 1, exceed the max allowed length by k
         *     dp[i][j] -= sum(dp[k - 1]) - dp[k - 1][j]
         */

        constexpr int kMod = 1e9 + 7;
        constexpr int rolls = 6;
        // dp[i][j]
        vector<vector<int>> dp(n + 1, vector<int>(rolls));
        vector<int> sums(n + 1);

        for (size_t j = 0; j < rolls; ++j) {
            sums[1] += dp[1][j] = 1;
        }

        for (size_t i = 2; i <= n; ++i) {
            for (size_t j = 0; j < 6; ++j) {
                const int k = i - rollMax[j];
                const int invalid = k <= 1 ? max(k, 0) : sums[k - 1] - dp[k - 1][j];
                dp[i][j] = ((sums[i - 1] - invalid) % kMod + kMod) % kMod;
                sums[i] = (sums[i] + dp[i][j]) % kMod;
            }
        }

        return sums[n];
    }
};
