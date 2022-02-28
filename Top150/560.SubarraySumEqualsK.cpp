#include "../Common.h"


// similar to 2 sums
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (accumulate(nums.begin(), nums.end(), 0) < k)
            return 0;

        int res = 0,
            sum = 0;

        unordered_map<int, int> m = {{0, 1}};
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            res += m[sum - k];
            m[sum]++;
        }
        return res;
    };
};