#include "../Common.h"


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // prerequisites -> adjacency list
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> pre_order(numCourses, 0);
        for (const vector<int>& p : prerequisites) {
            graph[p[1]].push_back(p[0]);
            ++pre_order[p[0]];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (pre_order[i] == 0) {
                q.push(i);
            }
        }

        int counter = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ++counter;

            for (const auto& v : graph[u]) {
                if (--pre_order[v] == 0) {
                    q.push(v);
                }
            }
        }

        return counter == numCourses;
    }
};