#include "../Common.h"


class Solution {
public:
    int longestStrChain(vector<string>& words) {
        // auto comparator = [](string& s1, string& s2) {
        //     return s1.size() < s2.size();
        // };
        // sort(words.begin(), words.end(), comparator);
        unordered_set<string> words_set(words.begin(), words.end());
        unordered_map<string, int> dp;
        int res = 0;
        // for (const string& word : words) {
        //     // check if there's predecessor by leave one out 
        //     for (int i = 0; i < word.size(); ++i) {
        //         string predecessor = word.substr(0, i) + word.substr(i + 1);
        //         dp[word] = max(dp[word], 
        //                        dp.find(predecessor) == dp.end() ? 
        //                        1 : 
        //                        dp[predecessor] + 1);
        //     }
        //     res = max(res, dp[word]);
        // }

        for (const string& word : words) {
            res = max(res, dfs(words_set, dp, word));
        }
        return res;
    }

    int dfs(unordered_set<string>& words,
            unordered_map<string, int>& dp,
            const string& word) {
        if (dp.find(word) != dp.end())
            return dp[word];

        int res = 1;
        for (int i = 0; i < word.size(); ++i) {
            string predecessor = word.substr(0, i) + word.substr(i + 1);
            if (words.find(predecessor) != words.end()) {
                // recursion
                res = max(1 + dfs(words, dp, predecessor), res);
            }
        }

        dp[word] = res;
        return res;
    }
};