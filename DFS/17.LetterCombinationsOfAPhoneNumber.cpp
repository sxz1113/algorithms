#include "Common.h"


class Solution {
public:
    vector<string> res;
    vector<string> pad{
        "",     // 1
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return res;

        vector<char> v;
        dfs(0, v, digits);
        return res;
    }

private:
    void dfs(int i,
             vector<char> &v,
             const string &digits) {
        // hit leaf node -> solution
        if (i == digits.size()) {
            // convert char array to string
            res.push_back(string(v.begin(), v.end()));
            return;
        }

        for (char c : pad[digits[i] - '1']) {
            v.push_back(c);
            dfs(i + 1, v, digits);
            v.pop_back();
        }
    }
};
