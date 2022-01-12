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


// DP
class Solution70_DP {
public:
    int climbStairs(int n) {
        // Jumping frog problem in GA
        vector<int> res(n + 1, 0);
        res[0] = res[1] = 1;
        for (size_t i = 2; i <= n; i++) {
            res[i] = res[i - 1] + res[i - 2];
        }
        
        return res[n];
    }
};

// Memorization
class Solution70_MEM {
public:
    int climbStairs(int n) {
        res = vector<int>(n + 1, 0);
        return helper(n);
    }

private:
    vector<int>res;
    int helper(int n) {
        // boundary conditions
        if (n <= 1) {
            return 1;
        }

        // if there's already a state
        if (res[n] > 0) {
            return res[n];
        }

        res[n] = helper(n - 1) + helper(n - 2);
        return res[n];
    }
};


class NumArray {
public:
    NumArray(vector<int>& nums): sums_(nums){
        if (nums.empty()) {
            return;
        };

        for (size_t i = 1; i < nums.size(); i++) {
            sums_[i] += sums_[i - 1];
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0) {
            return sums_[right];
        }
        return sums_[right] - sums_[left - 1];
    }

private:
    vector<int>sums_;
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

class Solution53 {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int>res(nums.size());
        res[0] = nums[0];

        for (size_t i = 1; i < nums.size(); i++) {
            res[i] = (res[i - 1] > 0) ? res[i - 1] + nums[i] : nums[i];
        }
        return *max_element(res.begin(), res.end());
    }
};


class Solution62 {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> v(m + 1, vector<int>(n + 1, 0));
        v[1][1] = 1;

        for (size_t i = 1; i <= m; ++i) {
            for (size_t j = 1; j <= n; ++j) {
                if (i == 1 && j == 1) {
                    continue;
                } else {
                    v[i][j] = v[i - 1][j] + v[i][j - 1];
                }
            }
        }
        
        return v[m][n];
    }
};


class Solution221 {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        /**
         * @brief subproblem: 
         * let dp[x][y] := max size can achieve at (x, y) as bottom right point
         * if matrix[x][y] == 0
         *     dp[x][y] = 0 
         * else
         *     dp[x][y] = min(dp[x - 1][y], 
         *                    dp[x][y - 1],
         *                    dp[x - 1][y - 1]) + 1
         */
        if (matrix.empty()) {
            return 0;
        }

        int m = matrix.size(), 
            n = matrix[0].size();

        vector<vector<int>> sizes(m, vector<int>(n, 0));
        int max_size = 0;
        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < n; ++j) {
                sizes[i][j] = matrix[i][j] - '0';

                // if matrix[i][j] == 0, dp[i][j] = 0
                if (!sizes[i][j]) {
                    continue;
                }

                // check boundary
                if (!(i == 0 || j == 0)) {
                    sizes[i][j] = min(min(sizes[i - 1][j], sizes[i][j - 1]), 
                                      sizes[i - 1][j - 1]) + 1;
                }
                max_size = max(max_size, sizes[i][j] * sizes[i][j]);
                cout << sizes[i][j] << " ";
            }
            cout << endl;
        }

        return max_size;
    }
};

class Solution85 {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        /**
         * @brief subproblem
         * let dp[x][y] := max length of all 1's can achieve at (x, y).
         * must be sequence ends at column y
         * if matrix[x][y] == '0'
         *     dp[x][y] = 0
         * else
         *     dp[x][y] = d[x][y - 1] + 1
         */
        int m = matrix.size();

        if (m == 0) {
            return 0;
        }

        int n = matrix[0].size();

        vector<vector<int>> lengths(m, vector<int>(n, 0));
        int max_size = 0, val, l;

        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < n; ++j) {
                val = matrix[i][j] - '0';
                lengths[i][j] = (val == 0) ? 0 : lengths[i][j - 1] + 1;
                cout << lengths[i][j] << " ";
            }
            cout << endl;
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                l = INT_MAX;
                for (int k = i; k < m; ++k) {
                    l = min(l, lengths[k][j]);
                    if (l == 0) {
                        break;
                    }
                    max_size = max(max_size, l * (k - i + 1));
                }
            }
        }
        return max_size;
    }
};


class Solution131 {
    vector<vector<string>> res;
    vector<string> v;

public:
    vector<vector<string>> partition(string s) {
        helper(s, v, res, 0);
        return res;
    }

private:
    void helper(string s,
                vector<string> &v,
                vector<vector<string>> &res, 
                int p) {

        if (p == s.size()) {
            res.emplace_back(v);
        }

        string substr = "";
        for (int i = p; i < s.size(); i++) {
            substr += s.at(i);
            if (isPalindrome(substr)) {
                v.push_back(substr);
                helper(s, v, res, i + 1);
                v.pop_back();
            }
        }
    }

    bool isPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            if (s.at(i) != s.at(j)) {
                return false;
            }
        }

        return true;
    }
};


class Solution72 {
public:
    int minDistance(string word1, string word2) {
        /**
         * @brief subproblem: 
         * let min distance d(i, j) := minDistance(word1[0, ..., i], word2[0, ..., j])
         * d(i, j) = min(d(i - 1, j) + 1,             delete last char in word1
         *               d(i, j - 1) + 1,             insert last char in word2
         *               d(i - 1, j - 1) + diff)  replace last char <-> word1 & word2 if not equal
         */

        int m = word1.size(),
            n = word2.size();

        // init solution matrix, add padding
        vector<vector<int>> d(m + 1, vector<int>(n + 1, 0));
        for (size_t i = 0; i <= m; ++i)
            d[i][0] = i;

        for (size_t j = 0; j <= n; ++j)
            d[0][j] = j;

        for (size_t i = 1; i <= m; ++i) {
            for (size_t j = 1; j <= n; ++j) {
                int c = (word1[i - 1] == word2[j - 1]) ? 0 : 1;
                d[i][j] = min(d[i - 1][j - 1] + c,
                              min(d[i - 1][j], d[i][j - 1]) + 1);
            }
        }

        return d[m][n];
    }
};


class Solution1223 {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        /**
         * @brief subproblem:
         * let dp[i][j] := the # of distinct sequences a1, a2, ..., aj ends with j
         * i - length of the sequence
         * 
         * for j = 1 ... 6, dp[1][j] = 1
         * (only 1 distinct seq possible when the length is 1)
         * 
         * dp[i][j] = sum(dp[i - 1])
         * k = i - rollMax[j]
         * if k == 1, just exceed the max allowed length by 1
         *     dp[i][j] -= 1
         * if k > 1, exceed the max allowed length by k
         *     dp[i][j] -= sum(dp[k - 1]) - dp[k - 1][j]
         */

        constexpr int kMod = 1e9 + 7;
        constexpr int rolls = 6;
        // dp[i][j]
        vector<vector<int>> dp(n + 1, vector<int>(rolls));
        vector<int> sums(n + 1);

        for (size_t j = 0; j < rolls; ++j) {
            sums[1] += dp[1][j] = 1;
        }

        for (size_t i = 2; i <= n; ++i) {
            for (size_t j = 0; j < 6; ++j) {
                const int k = i - rollMax[j];
                const int invalid = k <= 1 ? max(k, 0) : sums[k - 1] - dp[k - 1][j];
                dp[i][j] = ((sums[i - 1] - invalid) % kMod + kMod) % kMod;
                sums[i] = (sums[i] + dp[i][j]) % kMod;
            }
        }

        return sums[n];
    }
};


class Solution322 {
public:
    int coinChange(vector<int>& coins, int amount) {
        /**
         * @brief subproblem
         * let T[w] := min number of coins achievable with a knapsack of capacity w,
         * for a0, ..., ai including ai
         * -> removing ai from T[w] results to an optimal solution to T[w - wi]
         * -> T[w] = T[w - wi] + vi
         * -> T[w] = min(T[w - wi] + vi) for w = 1 to w
         */
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int coin : coins) {
            for (int capacity = coin; capacity <= amount; ++capacity) {
                if (dp[capacity - coin] != INT_MAX) {
                    dp[capacity] = min(dp[capacity], dp[capacity - coin] + 1);
                }
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};


class Solution746 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        const int n = cost.size();
        vector<int> res(n + 1, 0);
        res[0] = cost[0];
        res[1] = cost[1];
        
        for (int i = 2; i <= n; ++i) {
            res[i] = min(res[i - 1] + cost[i - 1], 
                         res[i - 2] + cost[i - 2]);
            cout << res[i] << " ";
        }
        cout << endl;
        return res[n];
    }
};


int main(int argc, char* argv[]) {
    return 0;
}
