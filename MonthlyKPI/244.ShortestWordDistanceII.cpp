#include "../Common.h"


class WordDistance {
public:
    WordDistance(vector<string>& wordsDict) {
        for (int i = 0; i < wordsDict.size(); ++i) {
            kv[wordsDict[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int i = 0,
            j = 0,
            res = INT32_MAX;

        while (i < kv[word1].size() && j < kv[word2].size()) {
            res = min(res, abs(kv[word1][i] - kv[word2][j]));
            if (kv[word1][i] < kv[word2][j]) {
                ++i;
            } else {
                ++j;
            }
        }
        return res;
    }

private:
    unordered_map<string, vector<int>> kv;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */