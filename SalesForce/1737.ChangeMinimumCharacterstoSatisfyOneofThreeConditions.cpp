#include "../Common.h"


class Solution {
public:
    int minCharacters(string a, string b) {
        const int letters = 26;
        int m = a.size(), 
            n = b.size(), 
            res = m + n;
        vector<int> freq_a(letters), freq_b(letters);

        for (const char& c : a)
            freq_a[c - 'a']++;

        for (const char& c : b)
            freq_b[c - 'a']++;

        for (int i = 0; i < letters; ++i) {
            // 3. Both a and b consist of only one distinct letter.
            res = min(res, m + n - freq_a[i] - freq_b[i]);
            if (i > 0) {
                freq_a[i] += freq_a[i - 1];
                freq_b[i] += freq_b[i - 1];
            }
            if (i < 25) {
                res = min(res, m - freq_a[i] + freq_b[i]);
                res = min(res, n - freq_b[i] + freq_a[i]);
            }
        }
        return res;
    }
};
