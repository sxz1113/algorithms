#include "../Common.h"


class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), prefix_sum = 0;

        for (int i = 0; i < k; ++i) {
            prefix_sum += cardPoints[i];
        }

        int res = prefix_sum;
        for (int suffix_sum = 0, i = 0; i < k; ++i) {
            suffix_sum += cardPoints[n - i - 1];
            prefix_sum -= cardPoints[k - i - 1];
            res = max(res, prefix_sum + suffix_sum);
        }

        return res;
    }
};