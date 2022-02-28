#include "../Common.h"


class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // given adjacency list, output isBipartite
        // tag: BFS, coloring technique
        int n = graph.size();

        // edge case, node 0 has no edges
        if (n == 0)
            return true;

        queue<int> q;
        vector<int> colors(n, 0);
        q.push(0);
        int node;

        for (int i = 0; i < n; ++i) {
            if (colors[i] == 0) {
                colors[i] = 1;
                q.push(i);
            }
            while (!q.empty()) {
                node = q.front();
                q.pop();
                for (const int& j : graph[node]) {
                    if (colors[j] == 0) {
                        q.push(j);
                        colors[j] = colors[node] == 2 ? 1 : 2;
                    } else if (colors[node] == colors[j]) {
                        return false;
                    }
                }
            }
        }

        // if no conflict
        return true;
    }
};