#include "../Common.h"


/*
Explanation
First, I count the number of 1 or 0 grouped consecutively.
For example "0110001111" will be [1, 2, 3, 4].

Second, for any possible substrings with 1 and 0 grouped consecutively, the number of valid substring will be the minimum number of 0 and 1.
For example "0001111", will be min(3, 4) = 3, ("01", "0011", "000111")


Complexity
Time O(N)
Space O(1)
*/
class Solution {
public:
    int countBinarySubstrings(string s) {
        int pre = 0, cur = 1, res = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) {
                cur++;
            } else {
                res += min(pre, cur);
                pre = cur;
                cur = 1;
            }
        }
        return res + min(pre, cur);
    }
};
