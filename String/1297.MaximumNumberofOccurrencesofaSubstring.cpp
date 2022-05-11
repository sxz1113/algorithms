#include "../Common.h"


class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int i = 0, j;
        int n = s.size(), res = 0;
        unordered_map<string, int> counter;
        for (int i = 0; i <= n - minSize; ++i) {
            string sub_str = s.substr(i, minSize);
            unordered_set<char> char_set(sub_str.begin(), sub_str.end());
            // cout << sub_str << ": " << char_set.size() << endl;
            if (char_set.size() <= maxLetters) {
                ++counter[sub_str];
            }
        }

        for (auto it : counter)
            res = max(res, it.second);

        return res;
    }
};