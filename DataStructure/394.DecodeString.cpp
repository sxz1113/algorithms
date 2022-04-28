#include "../Common.h"


class Solution {
public:
    string decodeString(string s) {
        // 常规符号匹配 => 第一反应stack, 相似题有32
        // 遇到 `([{` push, 遇到 `}])` pop
        stack<pair<int, string>> stk;
        string res {};
        int k = 0;
        for (const char &c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - 48);
            } else if (isalpha(c)) {
                res += c; 
            } else if (c == '[') {
                // cout << k << ", " << res << endl;
                stk.push({k, res});
                res.clear();
                k = 0;
            } else if (c == ']') {
                auto p = stk.top();
                stk.pop();
                
                string rep {res};
                res = p.second;
                while (p.first-- > 0)
                    res += rep;
            }
        }

        return res;
    }
};
