#include "Common.h"


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        /**
         * @brief subproblem
         * let T[w] := min number of coins achievable with a knapsack of capacity w,
         * for a0, ..., ai including ai
         * -> removing ai from T[w] results to an optimal solution to T[w - wi]
         * -> T[w] = T[w - wi] + vi
         * -> T[w] = min(T[w - wi] + vi) for w = 1 to w
         */
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int coin : coins) {
            for (int capacity = coin; capacity <= amount; ++capacity) {
                if (dp[capacity - coin] != INT_MAX) {
                    dp[capacity] = min(dp[capacity], dp[capacity - coin] + 1);
                }
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};