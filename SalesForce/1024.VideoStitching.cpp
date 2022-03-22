#include "../Common.h"


class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        /**
         * @brief tag - DP
         * subproblem: let T[i] = min number of clips needed to cover the event [0, i]
         * recurrence: T[i] = min(T[i], T[left of clip] + 1) for every clip
         */
        const int L = 0;
        const int R = 1;
        const int timeout = time + 1;
        vector<int> dp(time + 2, timeout);
        dp[0] = 0;
        for (int i = 0; i < timeout; i++) {
            for (const vector<int>& clip : clips) {
                // for every clip, if the range of current clip DOES include i 
                // check min number of clips needed to cover event [0, clip-left] + [clip-left, clip-right]
                if (clip[L] <= i && i <= clip[R]) {
                    dp[i] = min(dp[i], dp[clip[L]] + 1);
                }
            }

            if (dp[i] >= timeout)
                return -1;
        }
        return dp[time];
    }
};