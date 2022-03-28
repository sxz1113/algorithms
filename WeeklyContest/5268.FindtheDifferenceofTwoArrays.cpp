#include "../Common.h"


class Solution {
public:
    // two pointer???
    int minDeletion(vector<int>& nums) {
        int offset = 0, 
            n = nums.size(),
            res = 0;

        for (int i = 0; i < n; ++i) {
            if ((i + offset) % 2 == 0 && nums[i] == nums[i + 1]) {
                // printf("%d: %d -- %d\n", i + offset, nums[i + offset], nums[i + offset + 1]);
                res++;
                offset++;
            }
        }
        return res;
    }
};


class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        vector<long long> res(queries.size());
        int n = queries.size();
        int len = (intLength + 1) / 2;
        printf("half len = %d\n", len);
        int max_query = 1;

        for (int i = 1; i < len; ++i)
            max_query *= 10;

        max_query *= 9;
        printf("max query = %d\n", max_query);
        stack<int> stk;

        for (int i = 0; i < n; ++n) {
            int query = queries[i] - 1;
            if (query >= max_query) {
                res.push_back(-1);
            } else {
                while (query > 1) {
                    stk.push(query % 10);
                    query /= 10;
                }

                while (!stk.empty()) {
                    int d = stk.top();
                    int s {};
                    stk.pop();
                }
                
            }
        }
    }
};