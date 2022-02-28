#include "Common.h"


class Solution {
    vector<vector<string>> res;
    vector<string> v;

public:
    vector<vector<string>> partition(string s) {
        helper(s, v, res, 0);
        return res;
    }

private:
    void helper(string s,
                vector<string> &v,
                vector<vector<string>> &res, 
                int p) {

        if (p == s.size()) {
            res.emplace_back(v);
        }

        string substr = "";
        for (int i = p; i < s.size(); i++) {
            substr += s.at(i);
            if (isPalindrome(substr)) {
                v.push_back(substr);
                helper(s, v, res, i + 1);
                v.pop_back();
            }
        }
    }

    bool isPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            if (s.at(i) != s.at(j)) {
                return false;
            }
        }

        return true;
    }
};
