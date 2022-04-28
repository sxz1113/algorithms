#include "../Common.h"


class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        // Tag: ordered map
        // 分析：
        // 奇数次跳跃时，对于一些索引 i，下一步应该跳到哪里去（如果有的话）。
        // 我们可以使用 map，一个维护有序数据的绝佳数据结构。我们将索引 i 映射到 v = A[i] 上。
        // 从 i = N-2 到 i = 0 的遍历过程中，对于 v = A[i]，我们想知道比它略大一点和略小一点的元素是谁。
        // map.lower_bound() 与 map.upper_bound() 函数就是用来做这样一件事情的。
        // 思路：
        // 我们使用动态规划来维护 odd[i] 和 even[i]：从索引 i 出发奇数次跳跃与偶数次跳跃是否能到达数组末尾。
        int n = arr.size();
        // edge case
        if (n <= 1)
            return n;

        vector<bool> odd(n), even(n);
        // we have reached the end already
        odd[n - 1] = even[n - 1] = true;

        // key - arr[i], value - index i
        map<int, int> kv{{arr.back(), n - 1}};
        // 从后往前考虑
        for (int i = n - 2; i >= 0; --i) {
            int v = arr[i];
            // v是否能找到下一步跳跃的位置？需要
            // odd[i] = even[j], even[i] = odd[j]
            // lower_bound => ptr < v
            auto iter_lo = kv.lower_bound(v);
            // upper_bound => ptr >= v
            auto iter_hi = kv.upper_bound(v);

            // odd jump arr[i] <= arr[j]
            if (iter_lo != kv.end() && even[iter_lo->second])
                odd[i] = true;

            // even jump: arr[i] >= arr[j]
            if (iter_hi != kv.begin() && odd[(--iter_hi)->second])
                even[i] = true;

            kv[v] = i;
        }

        return accumulate(odd.begin(), odd.end(), 0);
    }
};