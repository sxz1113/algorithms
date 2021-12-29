#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <type_traits>
#include <unordered_map>
#include <vector>
#include <stack>
#include <limits>


using namespace std;


class Solution46 {
    vector<vector<int>> res;

public:
    int dfs(int x, int y) {
        int best = numeric_limits<int>::max();
        if (x == n) {
            if (sum < best) {
                best = sum;
            }
        }
    }
};



int main(int argc, char* argv[]) {
    vector<int> test {1, 2, 3};
    Solution46().permute(test);
}
