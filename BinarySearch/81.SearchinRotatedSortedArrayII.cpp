#include "../Common.h"


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0,
            end = nums.size() - 1,
            mid;

        while (start + 1 < end) {
            mid = start + (end - start) / 2;

            if (nums[start] == nums[mid]) {
                ++start;
            } else if (nums[mid] < nums[end]) {
                if (nums[mid] < target && target < nums[end]) {
                    start = mid;
                } else {
                    end = mid;
                }
            } else {
                if (nums[start] < target && target < nums[mid]) {
                    end = mid;
                } else {
                    start = mid;
                }
            }
        }

        if (nums[start] == target)
            return start;

        if (nums[end] == target)
            return end;
    }
};