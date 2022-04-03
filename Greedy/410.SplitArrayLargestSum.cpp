#include "../Common.h"


class Solution {
    // tag: greedy + binary search
public:
    int splitArray(vector<int>& nums, int m) {
        // find lower bound and upper bound of the subarray sum
        int lo = *max_element(nums.begin(), nums.end());
        int hi = accumulate(nums.begin(), nums.end(), 0);

        // binary search divied point, greedily pushing res moving -> the lower bound
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (split_with_upper_bound(nums, mid, m - 1)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }

private:
    bool split_with_upper_bound(vector<int>& nums, 
                   int sum_max, 
                   int cuts) {
        int sum_cur = 0;
        // Just fly over all elements in the array, 
        // and find the stop point along the way.
        for (int num : nums) {
            // restart if incorporating num makes current subarray sum exceed sum_max
            if (sum_cur > sum_max - num) {
                sum_cur = num;
                --cuts;
            } else {
                sum_cur += num;
            }

            if (cuts < 0)
                return false;
        }
        return true;
    }
};