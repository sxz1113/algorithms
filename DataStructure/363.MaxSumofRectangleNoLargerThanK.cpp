#include "../Common.h"


class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        // prefix sum和sorted container
        int res = INT_MIN;
        int n_rows = matrix.size(),
            n_cols = matrix[0].size();
        vector<int> prefix_sums(n_rows, 0);

        // slicing windows / columns
        // 选定任意两列之后，可以利用行方向上的prefix sum转化为一维的问题:
        // max sum of subarray NO larger than K，时间复杂度可以降为o(m * m * n * logn)
        for (int i_col = 0; i_col < n_cols; ++i_col) {
            // 移动左指针 / column边界，初始化prefix sum
            fill(prefix_sums.begin(), prefix_sums.end(), 0);
            for (int j_col = i_col; j_col < n_cols; ++j_col) {
                for (int i_row = 0; i_row < n_rows; ++i_row)
                    prefix_sums[i_row] += matrix[i_row][j_col];

                // 查找max sum of subarray NO larger than K
                // 搜索在j之前的元素是否有i满足条件 sum[j] - sum[i] < k
                set<int> s{0};
                int sum = 0, sum_max = INT_MIN;
                for (const int &prefix_sum : prefix_sums) {
                    sum += prefix_sum;
                    auto iter = s.lower_bound(sum - k);
                    // 若存在i满足条件，更新结果
                    if (iter != s.end())
                        sum_max = max(sum_max, sum - *iter);

                    // 并将j元素对应的结果加入prefix sum。
                    s.insert(sum);
                }
                res = max(res, sum_max);
            }
        }

        return res;
    }
};