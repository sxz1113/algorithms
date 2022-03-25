#include "../Common.h"


class Solution {
    // Tag: binary search
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1, 
            end = *max_element(nums.begin(), nums.end()), 
            mid;

        while (start + 1 < end) {
            mid = start + (end - start) / 2;
            if (divided_sum(nums, mid) > threshold) {
                start = mid;
            } else {
                end = mid;
            }
        }

        if (divided_sum(nums, start) <= threshold)
            return start;

        return end;
    }

private:
    int divided_sum(const vector<int>& nums, int divisor) {
        int res = 0;
        for (const int num : nums) {
            res += (1 + (num - 1) / divisor);
        }
        // printf("divisor = %d, divided sum = %d\n", divisor, res);
        return res;
    }
};