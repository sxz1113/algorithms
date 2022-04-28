#include "../Common.h"


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int res = 0;
        int sum = 0;
        // 用一个map记录每个位置的accumulated sum: 
        // key - accumulated sum, value - idx / position 
        unordered_map<int, int> m;
        m[0] = -1;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i] == 1 ? 1 : -1;
            if (m.find(sum) == m.end()) {
                m[sum] = i;
            } else {
                res = max(res, i - m[sum]);
            }
        }
        return res;
    }
};