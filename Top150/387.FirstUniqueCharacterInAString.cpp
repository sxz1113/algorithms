#include "Common.h"


// using map
class SolutionMap {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;

        for (char &c : s)
            m[c] += 1;

        for (int i = 0; i < s.size(); ++i)
            if (m[s[i]] == 1)
                return i;

        return -1;
    }
};


// using vector
class SolutionVector {
public:
    int firstUniqChar(string s) {
        vector<int> count(26, 0);

        for (char &c : s)
            count[c - 'a'] += 1;

        for (int i = 0; i < s.size(); ++i)
            if (count[s[i] - 'a'] == 1)
                return i;

        return -1;
    }
};
