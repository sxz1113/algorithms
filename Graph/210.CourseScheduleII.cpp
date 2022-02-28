#include "../Common.h"


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> pre_order(numCourses, 0), res;

        for (const vector<int>& p : prerequisites) {
            graph[p[1]].push_back(p[0]);
            ++pre_order[p[0]];
        }

        queue<int> q;

        for (int i = 0; i < pre_order.size(); ++i) {
            if (!pre_order[i])
                q.push(i);
        }

        while (!q.empty()) {
            int u = q.front();
            res.push_back(u);
            q.pop();
            for (const auto& v: graph[u]) {
                --pre_order[v];
                if (pre_order[v] == 0) {
                    q.push(v);
                } 
            }
        }

        for (int i = 0; i < pre_order.size(); ++i) {
            // detect cycle
            if (pre_order[i])
                return vector<int>();
        }

        return res;
    }
};