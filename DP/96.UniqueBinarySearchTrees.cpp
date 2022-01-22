#include "Common.h"


class Solution {
public:
    int numTrees(int n) {
        /**
         * @brief subproblem
         * Let T[i] := number of unique BST with n nodes of unique values from 1 to n
         * Note: The input is a rooted tree. A subproblem is a rooted subtree.
         * T[i] = sum(T[j] * T[i - j - 1]), where j = 0, ..., n - 1 
         * root: 1 node, varied from 1 to n
         * left child: j node
         * rigth child: i - j - 1 node
         */

        // init array with base case base case
        vector<int> dp (n + 1);
        dp[0] = 1;

        for (int i = 1; i <= n; ++i)
            for (int j = 0; j < i; ++j)
                dp[i] += dp[j] * dp[i - j - 1];

        return dp.back();
    }
};