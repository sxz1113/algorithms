#include "../Common.h"


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        // edge case
        int n = nums.size();
        if (n < 3)
            return res;

        // sort input space
        sort(nums.begin(), nums.end());

        int target, sum, j, k;
        for (int i = 0; i < nums.size(); ++i) {
            // skip duplicates of the first element
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // fix 1st number
            target = -nums[i];
            // search 2nd and 3rd number
            j = i + 1;
            k = n - 1;

            while (j < k) {
                sum = nums[j] + nums[k];
                if (sum == target) {
                    res.push_back(vector<int> {nums[i], nums[j], nums[k]});
                    // skip duplicates of the second and third element
                    while (j < k && nums[j] == res.back()[1])
                        j++;
                    while (j < k && nums[k] == res.back()[2])
                        k--;
                } else if (sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }

        return res;
    }
};
