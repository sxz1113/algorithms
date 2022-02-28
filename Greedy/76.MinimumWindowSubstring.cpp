#include "../Common.h"


class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() == 0 || t.size() == 0)
            return "";

        vector<int> checksum(128, 0);
        int required = t.size();
        for (char c : t)
            checksum[c]++;
        
        int sz_min = s.size() + 1,
            l = 0,
            l_min = 0,
            r = 0;

        while (r <= s.size() && l < s.size()) {
            if (required > 0) {
                if (r == s.size())
                    break;

                if (--checksum[s[r]] >= 0)
                    required--;
                r++;
            } else {
                if (r - l < sz_min) {
                    sz_min = r - l;
                    l_min = l;
                }

                if (++checksum[s[l]] > 0)
                    required++;
                l++;
            }
        }
        return sz_min == s.size() + 1 ? "": s.substr(l_min, sz_min);
    }
};
