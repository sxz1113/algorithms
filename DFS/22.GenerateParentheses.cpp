#include "Common.h"


class Solution {
private:
    vector<string> res_;

    void dfs (string s,
              int l,
              int r) {
        // 递归出口
        if (l == 0 && r == 0) {
            res_.push_back(s);
            return;
        }

        // 选（ left
        if (l > 0)
            dfs(s + "(", l - 1, r + 1);

        // 选 ) right
        if (r > 0)
            dfs(s + ")", l, r - 1);
    }


    
public:
    vector<string> generateParenthesis(int n) {
        dfs("", n, 0);
        return res_;
    }
};