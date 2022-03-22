#include "../Common.h"
#include <random>


class Solution {
public:
    Solution(vector<int>& w) {
        srand(time(NULL));
        // 建立权重数组的累加和数组
        for (const int i : w) {
            int prev =  w_.empty() ? 0 : w_.back();
            w_.push_back(i + prev);
        }
    }

    int pickIndex() {
        // 随机取范围[0, total_weight]的数
        int x = rand() % w_.back();
        // 使用binary search / upper_bound() 找到第一个大于随机数x的数字的 index
        return upper_bound(w_.begin(), w_.end(), x) - w_.begin();
    }

private:
    vector<int> w_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */