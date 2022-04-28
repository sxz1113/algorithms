#include "../Common.h"


class Solution {
public:
    string minimizeResult(string expression) {
        string res;
        long long eval = INT32_MAX, p = expression.find('+');
        string l = expression.substr(0, p);
        string r = expression.substr(p + 1);

        int i = 0, j = r.size();
        for (int i = 0; i < l.size(); ++i) {
            for (int j = r.size(); j > 0; --j) {
                string t1 = l.substr(0, i);
                int i1 = t1.empty() ? 1 : stoi(t1);

                string t2 = l.substr(i);
                int i2 = stoi(t2);

                string t3 = r.substr(0, j);
                int i3 = stoi(t3);

                string t4 = r.substr(j);
                int i4 = t4.empty() ? 1 : stoi(t4);

                long long sum = i1 * (i2 + i3) * i4;
                if (sum < eval) {
                    res = t1 + "(" + t2 + "+" + t3 + ")" + t4;
                    eval = sum;
                }
            }
        }
        return res;
    }
};