#include "../Common.h"


class SparseVector {
public:
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                kv[i] = nums[i];
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int res = 0;

        for (auto& [k, v] : kv) {
            if (vec.getVector().count(k))
                res += v * vec.getVector()[k];
        }

        return res;
    }

    unordered_map<int, int> getVector() {
        return kv;
    }

private:
    unordered_map<int, int> kv;
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);