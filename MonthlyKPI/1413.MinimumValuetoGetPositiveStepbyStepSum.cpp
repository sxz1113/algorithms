#include "../Common.h"


class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, res = 0;
        
        for (int &num : nums) {
            sum += num;
            res = min(res, sum);
        }
        return 1 - res;
    }
};