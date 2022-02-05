#include "../Common.h"


class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> check_sum(26, 0);
        if (s.size() != t.size())
            return false;

        for (size_t i = 0; i < s.size(); i++) {
            check_sum[s[i] - 'a'] += 1;
            check_sum[t[i] - 'a'] -= 1;
        }

        for (int i : check_sum)
            if (i)
                return false;

        return true;
    }
};