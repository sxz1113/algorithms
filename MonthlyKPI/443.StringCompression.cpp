#include "../Common.h"


class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, j = 0, len;
        string s;
        while (i < chars.size()) {
            chars[j] = chars[i];
            len = 0;
            while (i < chars.size() && chars[i++] == chars[j]) {
                len++;
            }

            if (len > 1) {
                s = to_string(len);
                for (char& c : s)
                    chars[++j] = c;
            }
            j++;
        }
        return j;
    }
};