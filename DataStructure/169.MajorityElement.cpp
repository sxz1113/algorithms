#include "../Common.h"


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /* hash table approach
        unordered_map<int, int> kv;
        int n = nums.size();
        for (int num : nums) {
            if (++kv[num] > n / 2)
                return num;
        }
        return 0;
        */

        // Divide & Conque approach
        return helper(nums, 0, nums.size() - 1);
    }

private:
    int helper(vector<int> &nums, int left, int right) {
        if (left == right)
            return nums[left];

        // mid point
        const int mid = left + (right - left) / 2;
        // divide, get majority element on the left / right half, respectively
        const int ml = helper(nums, left, mid);
        const int mr = helper(nums, mid + 1, right);

        // merge and conquer
        if (ml == mr)
            return ml;

        auto i0 = nums.begin();
        return count(i0 + left, i0 + right + 1, ml) > 
               count(i0 + left, i0 + right + 1, mr) ?
               ml : mr;
    }
};
