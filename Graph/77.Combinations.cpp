#include "../Common.h"


class Solution {
public:
    // 排列回溯的是交换的位置,
    // 组合回溯的是否把当前的数字加入结果中。
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> vec(k, 0);
        int cnt = 0;
        backtracking(res, vec, 1, cnt, n);
        return res;
    }

    void backtracking(vector<vector<int>>& res,
                      vector<int>& vec,
                      int cur,
                      int& cnt,
                      const int n) {
        if (cnt == vec.size()) {
            res.push_back(vec);
            return;
        }

        for (int i = cur; i <= n; ++i) {
            printf("add %d", i);
            vec[cnt++] = i;
            backtracking(res, vec, i + 1, cnt, n);
            cnt--;
        }
    }
};