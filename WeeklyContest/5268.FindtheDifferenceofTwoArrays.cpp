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
        vector<long long> res(queries.size(), -1);
        int n = queries.size();
        int half_len = (intLength + 1) / 2;
        int max_queries = 9 * pow(10L, half_len - 1);
        long start = pow(10L, (intLength - 1) / 2);
        // printf("half len = %d, max query = %d\n", 
        //        half_len, 
        //        max_queries);

        for (int i = 0; i < n; ++i) {
            if (queries[i] <= max_queries) {
                res[i] = generate_palindrome(start + queries[i] - 1, intLength % 2);
            }
        }
        return res;
    }

private:
    long long generate_palindrome(long long half, bool is_odd) {
        long long res = half;
        if (is_odd)
            half /= 10;

        while (half > 0) {
            res = res * 10 + half % 10;
            half /= 10;
        }

        return res;
    }
};