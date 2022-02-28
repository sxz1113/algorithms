#include "../Common.h"


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // edge case
        if (nums.size() == 0)
            return vector<int> {-1, -1};

        int lower = lower_bound(nums, target);
        int upper = upper_bound(nums, target);

        return vector<int> {lower, upper};
    }

private:
    int lower_bound(vector<int>& nums, int target) {
        int start = 0,
            end = nums.size() - 1,
            mid, lower, upper;

        while (start + 1 < end) {
            mid = start + (end -  start) / 2;
            if (nums[mid] >= target) {
                end = mid;
            } else {
                start = mid;
            }
        }

        // postprocessing
        if (nums[start] == target) {
            return start;
        }

        if (nums[end] == target) {
            return end;
        }

        return -1;
    }

    int upper_bound(vector<int>& nums, int target) {
        int start = 0,
            end = nums.size() - 1,
            mid, lower, upper;

        while (start + 1 < end) {
            mid = start + (end -  start) / 2;
            if (nums[mid] > target) {
                end = mid;
            } else {
                start = mid;
            }
        }

        // postprocessing
        if (nums[end] == target) {
            return end;
        }

        if (nums[start] == target) {
            return start;
        }

        return -1;
    }
};