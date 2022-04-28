#include "../Common.h"


int gcd (int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int res = 0;
        map<pair<int, int>, int> m;
        pair<int, int> k;

        for (int i = 0; i < n; ++i) {
            m.clear();
            for (int j = i + 1; j < n; ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == dy) {
                    k = make_pair(1, 1);
                } else {
                    int div = gcd(dx, dy);
                    k = make_pair(dx / div, dy / div);
                }
                res = max(res, ++m[k]);
            }
        }

        return res + 1;
    }
};