#include "../Common.h"


class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        n = parents.size();

        // reconstruct the map
        for (int i = 0; i < n; ++i) {
            graph[parents[i]].push_back(i);
        }

        // for (const auto &kv : graph) {
        //     cout << kv.first << ": ";
        //     for (const int& i : kv.second)
        //         cout << i << ", ";

        //     cout << endl;
        // }

        dfs(0);
        return res;
    }

private:
    unordered_map<int, vector<int>> graph;
    int n;
    int res;
    long highest_score = 0;
    int dfs(int node) {
        int left = 0, right = 0;

        // recursion
        if (graph.find(node) != graph.end()) {
            left = dfs(graph[node].back());
            right = graph[node].size() > 1 ? dfs(graph[node].front()) : 0;
        }

        long score = (long) max(1, left) * 
                     (long) max(1, right) * 
                     (long) max(1, n - 1 - left - right);

        if (score > highest_score) {
            highest_score = score;
            // reset res
            res = 1;
        } else if (score == highest_score) {
            ++res;
        }

        return left + 1 + right;
    }
};
