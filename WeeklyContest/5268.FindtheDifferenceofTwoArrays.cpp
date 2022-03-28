#include "../Common.h"


class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v1, v2;
        set<int> s1(nums1.begin(), nums1.end()), 
                 s2(nums2.begin(), nums2.end());
        set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), 
                       back_inserter(v1));
        set_difference(s2.begin(), s2.end(), s1.begin(), s1.end(), 
                       back_inserter(v2));
        return { v1, v2 };
    }
};


class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size(),
            res = 0;

        for (int i = 0; i < n - 1; ++i) {
            // check condition 2
            if ((i - res) % 2 == 0 && nums[i] == nums[i + 1])
                res++;
        }

        // check if the length of nums is even
        return res + (n - res) % 2;
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