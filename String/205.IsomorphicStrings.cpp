#include "../Common.h"


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;

        // s and t consist of any valid ascii character.
        vector<int> s_map(256, -1), t_map(256, -1);
        for (int i = 0; i < s.size(); ++i) {
            if (s_map[s[i]] != t_map[t[i]])
                return false;

            s_map[s[i]] = t_map[t[i]]= i;
        }
        return true;
    }
};