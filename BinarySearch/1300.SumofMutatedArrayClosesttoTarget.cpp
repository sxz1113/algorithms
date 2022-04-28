#include "../Common.h"


class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int l = 0,
            r = target / arr.size(),
            // r = 1e5,
            m;

        while (l < r) {
            m = l + (r - l) / 2;
            if (getDistance(arr, m, target) <= getDistance(arr, m + 1, target)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }

private:
    int getDistance(vector<int> &arr, int threshold, int target) {
        int res = 0;
        for (int n : arr)
            res += min(n, threshold);

        return abs(res - target);
    }
};
