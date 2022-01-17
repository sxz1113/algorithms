#include "Common.h"


class Solution {
public:
    int numSquares(int n) {
        /**
         * @brief subproblem
         * T[i] := min number of perfect square numbers that sum to i
         * T[i] = min(T[i - j ** 2] + 1, T[i])
         * 
         */
        // vector<int> dp(n + 1, INT_MAX);
        // dp[0] = 0;

        // for (int i = 1; i <= n; ++i)
        //     for (int j = 1; j * j <= i; ++j)
        //         dp[i] = min(dp[i - j * j] + 1, dp[i]);

        // return dp.back();

        vector<int> dp{0};
        while (dp.size() <= n) {
            int n = dp.size(),
                n_squares = INT_MAX;
            for (int i = 1; i * i <= n; ++i)
                n_squares = min(n_squares, dp[n - i * i] + 1);

            dp.push_back(n_squares);
        }
        return dp[n];
    }
};
