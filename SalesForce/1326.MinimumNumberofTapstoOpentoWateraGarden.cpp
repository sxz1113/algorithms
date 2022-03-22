#include "../Common.h"


class Solution {
    /**
     * @brief tag - DP
     * solution
     * subproblem: let T[i] = min number of taps to water garden [0, i]
     * recurrence: T[i] = min(T[i], T[left end of the tap can reach] + 1) for every tap
     */
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> dp(n + 1, n + 2);
        dp[0] = 0;
        // for (int i = 0; i < m; ++i) {
        //     intervals.push_back({max(0, i - ranges[i]), i + ranges[i]});
        // }

        // sort(intervals.begin(), intervals.end());

        for (int i = 0; i <= n; ++i) {
            int lower = i - ranges[i];
            int upper = i + ranges[i];
            for (int j = max(0, lower + 1); j <= min(upper, n); ++j) {
                dp[j] = min(dp[j], dp[max(0, lower)] + 1);
            }
        }

        return dp[n] < n + 2 ? dp[n] : -1;
    }
};