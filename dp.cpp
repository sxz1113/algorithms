#include "Common.h"


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


class Solution813 {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        /**
         * @brief subproblems - Knapsack without repetition
         * possible partition positions nums.size() - 1
         * let T[w] := max sum of averages of subarrays achievable with a knapsack of partition w 
         * and a0, ..., ai - 1 including ai - 1
         * -> is it necessary to put a divider after ai - 1
         * -> T[w, i] = max{T[w - wi, i - 1] + vi, T[w, i - i])
         *    for i = 1 to n and w = 1 to w
         */
        const int n = nums.size();

        // init k * n matrix
        vector<vector<double>> dp(k + 1, vector<double> (n + 1, 0.0));
        vector<double> sums(n + 1, 0.0);

        for (int i = 1; i <= n; ++i) {
            sums[i] = sums[i - 1] + nums[i - 1];
            dp[1][i] = static_cast<double>sums[i] / i;
        }

        for (int i = 2; i <= k; ++i) {
            for (int j = i; j <= n; ++j) {
                for (int l = i - 1; l < j; ++l) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][l] + (sums[j] - sums[l]) / (j - l));
                }
            }
        }
        return dp[k][n];
    }
};


class Solution1137 {
public:
    int tribonacci(int n) {
        vector<int> arr {0, 1, 1, 0};
        for (int i = 3; i < n; ++i) {
            arr[i % 4] = arr[(i - 1) % 4] + arr[(i - 2) % 4] + arr[(i -3) %4];
        }
        return arr[i % 4];
    }
};


class Solution198 {
public:
    int rob(vector<int>& nums) {
        // subproblem: dp[i] := max money after visiting nums[i]
        // dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])
        if (nums.empty())
            return 0;

        if (nums.size() == 1)
            return nums[0];

        vector<int> dp {nums[0], max(nums[0], nums[1]), 0};
        for (int i = 2; i < nums.size(); ++i)
            dp[i % 3] = max(dp[(i - 2) % 3] + nums[i], dp[(i - 1) % 3]);

        return dp[(nums.size() - 1) % 3];
    }
};


class Solution20 {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char &c : s) {
            switch (c) {
            case '(':
                st.push(')');
                break;

            case '[':
                st.push(']');
                break;

            case '{':
                st.push('}');
                break;

            default:
                if (st.empty() || c != st.top())
                    return false;
                else
                    st.pop();
                break;
            }
        }
        return st.empty() ? true : false;
    }
};


class Solution121 {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int price_min = INT_MAX;

        for (int i = 0; i < prices.size(); ++i) {
            price_min = min(price_min, prices[i]);
            res = max(res, prices[i] - price_min);
        }

        return res;
    }
};


int main(int argc, char* argv[]) {
    return 0;
}
