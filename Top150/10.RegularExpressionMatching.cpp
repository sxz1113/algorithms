#include "../Common.h"

// tag: DP
class Solution {
public:
    bool isMatch(string s, string p) {
        /**
         * @brief 双序列型DP
         * let dp[i][j] := isMatch(s[1:i], p[1:j])
         *   1. case p[j] is alphanumerical (not metachar): dp[i][j] = s[i] == p[j] && dp[i - 1][j - 1]
         *   2. case p[j] == '.': dp[i][j] = dp[i - 1][j - 1]
         *   3. case p[j] == '*': 
         *     3.1 重复0次: dp[i][j] = dp[i][j - 2]
         *     3.2 重复n次: dp[i][j] = s[i] == p[j - 1] || p[j - 1] == '.' && dp[i - 1][j]
         */

        int m = s.size(),
            n = p.size();
        // dp 二维bool数组，初始化为false
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // 初始化起始点 => true
        dp[0][0] = true;
        // 初始化边界
        // p[0.., j - 3, j - 2, j - 1] matches empty iff p[j - 1] is '*' and p[0..j - 3] matches empty
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = j > 1 && p[j - 1] == '*' && dp[0][j - 2];
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] || (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j];
                } else {
                    dp[i][j] = (p[j - 1] == '.' || s[i - 1] == p[j - 1]) && dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};
