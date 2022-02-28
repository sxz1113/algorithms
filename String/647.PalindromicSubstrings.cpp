#include "../Common.h"


class Solution {
public:
    // mem
    int countSubstringsMemorization(string s) {
        int n = s.size(), cnt = 0;
        vector<vector<int>> t(n, vector<int>(n, -1));
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i; j < s.size(); ++j) {
                cnt += isPalindrome(t, s, i, j);
            }
        }
        return cnt;
    }

    // DP
    int countSubstrings(string s) {
        int n = s.size(), cnt = 0;
        vector<vector<int>> t(n, vector<int>(n, -1));
        for (int i = n - 1; i < n; ++i) {
            t[i][i] = 1;
            cnt++;
            for (int j = i + 1; j < s.size(); ++j) {
                t[i][j] = (s[i] == s[j]) && t[i + 1][j - 1];
                cnt += t[i][j];
            }
        }
        return cnt;
    }

private:
    int isPalindrome(vector<vector<int>>& t, string& s, int i, int j) {
        if (i >= j)
            return 1;

        if (t[i][j] >= 0)
            return t[i][j];

        return s[i] == s[j] ? isPalindrome(t, s, i + 1, j - 1) : 0;
    }
};