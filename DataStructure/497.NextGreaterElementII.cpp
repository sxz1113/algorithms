#include "../Common.h"


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        stack<int> stk;
        // key - element in nums2, val - next greater element of key in nums2
        unordered_map<int, int> m;
        int n = nums.size();
        for (int i = 0; i < 2 * n; ++i) {
            while (!stk.empty() && nums[stk.top()] < nums[i % n]) {
                if (stk.top() < n)
                    m[nums[stk.top()]] = nums[i % n];
                stk.pop();
            }
            stk.push(i % n);
        }

        for (int i = 0; i < n; ++i) {
            if (m.find(nums[i]) != m.end())
                res[i] = m[nums[i]];
        }

        return res;
    }
};