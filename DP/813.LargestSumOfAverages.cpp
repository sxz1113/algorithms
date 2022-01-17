#include "Common.h"


class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        /**
         * @brief subproblems - Knapsack without repetition
         * possible partition positions nums.size() - 1
         * let T[w] := max sum of averages of subarrays achievable with a knapsack of partition w 
         * and a0, ..., ai - 1 including ai - 1
         * -> is it necessary to put a divider after ai - 1
         * -> T[w, i] = max{T[w - wi, i - 1] + vi, T[w, i - i])
         *    for i = 1 to n and w = 1 to w
         */
        const int n = nums.size();

        // init k * n matrix
        vector<vector<double>> dp(k + 1, vector<double> (n + 1, 0.0));
        vector<double> sums(n + 1, 0.0);

        for (int i = 1; i <= n; ++i) {
            sums[i] = sums[i - 1] + nums[i - 1];
            dp[1][i] = static_cast<double>(sums[i]) / i;
        }

        for (int i = 2; i <= k; ++i) {
            for (int j = i; j <= n; ++j) {
                for (int l = i - 1; l < j; ++l) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][l] + (sums[j] - sums[l]) / (j - l));
                }
            }
        }
        return dp[k][n];
    }
};
