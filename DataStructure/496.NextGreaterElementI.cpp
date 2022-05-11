#include "../Common.h"


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(), -1);
        stack<int> stk;
        // key - element in nums2, val - next greater element of key in nums2
        unordered_map<int, int> m;

        for (int i = 0; i < nums2.size(); ++i) {
            while (!stk.empty() && nums2[stk.top()] < nums2[i]) {
                m[nums2[stk.top()]] = nums2[i];
                stk.pop();
            }
            stk.push(i);
        }

        for (int i = 0; i < nums1.size(); ++i) {
            if (m.find(nums1[i]) != m.end())
                res[i] = m[nums1[i]];
        }

        return res;
    }
};