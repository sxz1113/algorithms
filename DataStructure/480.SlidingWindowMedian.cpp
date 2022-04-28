#include "../Common.h"


class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        // 选用能够自动排序的容器multiset, 初始化喂nums的前k个数
        multiset<int> s{nums.begin(), nums.begin() + k};
        auto iter = s.begin();
        for (int i = 0; i < k / 2; ++i)
            ++iter;

        for (int i = k; i <= nums.size(); ++i) {
            if (k % 2 == 1) {
                res.push_back((double) (*iter));
            } else {
                res.push_back((*iter) / 2.0 + *(--iter) / 2.0);
                ++iter;
            }

            if (i == nums.size())
                break;

            s.insert(nums[i]);
            // cout << "insert " << nums[i];
            if (nums[i] < *iter)
                --iter;

            if (nums[i - k] <= *iter)
                ++iter;

            // cout << " delete " << *s.lower_bound(nums[i - k]) << endl;
            // 要用lower bound，不然有duplicated element会一并删除
            s.erase(s.lower_bound(nums[i - k]));
        }

        return res;
    }
};
