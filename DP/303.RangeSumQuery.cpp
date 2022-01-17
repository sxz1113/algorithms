#include "Common.h"


class NumArray {
public:
    NumArray(vector<int>& nums): sums_(nums){
        if (nums.empty()) {
            return;
        };

        for (size_t i = 1; i < nums.size(); i++) {
            sums_[i] += sums_[i - 1];
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0) {
            return sums_[right];
        }
        return sums_[right] - sums_[left - 1];
    }

private:
    vector<int>sums_;
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */


























