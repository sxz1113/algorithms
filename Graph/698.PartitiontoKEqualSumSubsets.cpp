#include "../Common.h"

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        // edge case, not enough element to partition
        if (nums.size() < k || sum  % k != 0) {
            return false;
        }

        vector<bool> visited (nums.size(), false);
        return dfs(nums, visited, sum / k, sum / k, 0, 0, k);
    }

private:
    bool dfs(vector<int>& nums, 
             vector<bool> &visited,
             int target, 
             int rem,
             int cur_num,
             int start, 
             int k
             ) {
        if (k == 1)
            return true;

        // found a subset
        if (rem == 0 && cur_num > 0) {
            // cout << k << endl;
            return dfs(nums, visited, target, target, 0, 0, k - 1);
        }

        for (int i = start; i < nums.size(); ++i) {
            if (!visited[i] && nums[i] <= rem) {
                visited[i] = true;
                if (dfs(nums, visited, target, rem - nums[i], cur_num++, i + 1, k))
                    return true;

                visited[i] = false;
            }
        }
        return false;
    }
};