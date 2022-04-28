#include "../Common.h"


class Solution {
public:
    int hIndex(vector<int>& citations) {
        // 第一反应：binary search
        int l = 0, r = citations.size(), m;
        while (l + 1 < r) {
            m = l + (r - l) / 2;
            // 确定红蓝区间
            if (isFeasible(citations, m)) {
                l = m;
            } else {
                r = m;
            }
        }
        
        return isFeasible(citations, r) ? r : l;
    }
    
private:
    bool isFeasible(vector<int> &arr, int h) {
        int res = 0;
        for (int i : arr) {
            if (i >= h)
                ++res;
        }
        return res >= h;
    }
};