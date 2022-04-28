#include "../Common.h"

class Solution {
public:
// hash(s) => base-power整数
// + sliding window
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        int n = s.size();
        long long hash = 0, m = modulo, pk = 1;

        int res = -1;
        for (int i = n - 1; i >= 0; --i) {
            hash = (hash * power + s[i] - 'a' + 1) % m;
            // 猥琐发育一个k-sized window
            if (i + k >= n) {
                pk = pk * power % m;
            // 发育好啦，开始从后往前卷
            } else {
                hash = (hash - (s[i + k] - 'a' + 1) * pk % m + m) % m;
            }

            if (hash == hashValue)
                res = i;
        }
        return s.substr(res, k);
    }
};