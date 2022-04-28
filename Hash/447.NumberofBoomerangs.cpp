#include "../Common.h"


class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        // 固定一个点i，查找其他所有点到该点的距离，存进一个map
        unordered_map<pair<int, int>, int> m;
        int n = points.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                ++m[{i, dx * dx + dy * dy}];
            }
        }

        int res = 0;
        for (auto &kv : m) {
            printf("point #%d (%d, %d) has %d points of the same distance = %d\n", 
                kv.first.first,
                points[kv.first.first][0],
                points[kv.first.first][1],
                kv.second,
                kv.first.second
            );
            if (kv.second > 0)
                res += kv.second * (kv.second - 1);
        }
        return res;
    }
};