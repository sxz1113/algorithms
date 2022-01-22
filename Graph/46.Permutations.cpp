#include "Common.h"


class Solution {
    vector<vector<int>> res;

public:
    vector<vector<int>> permute(vector<int> &nums) {
        // edge case
        if (nums.size() == 0)
            return res;

        vector<int> v;
        // dfs(res, v, nums);
        helper(res, v, 0);
        return res;
    }

private:
    void dfs(vector<vector<int>> &res, 
             vector<int> &v,
             vector<int> &nums) {

        // hit leaf node -> solution
        if (v.size() == nums.size()) {
            res.emplace_back(v);
            return;
        }

        for (int num : nums) {
            if (find(v.begin(), v.end(), num) == v.end()) {
                // push to stack
                v.push_back(num);
                dfs(res, v, nums);
                // backtrack / pop out of stack
                v.pop_back();
            }
        }
    }

    // recursive solution, using swap
    void helper(vector<vector<int>> &res,
                vector<int> &nums,
                int n) {
        // boundary case
        if (nums.size() == n) {
            res.emplace_back(nums);
            return;
        }

        // in place swap value
        for (int i = n; i < nums.size(); ++i) {
            // swap
            swap(nums[n], nums[i]);
            helper(res, nums, n + 1);
            // backtrack / swap back
            swap(nums[n], nums[i]);
        }
    }

};
