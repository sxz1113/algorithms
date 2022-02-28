#include "Common.h"


// with O(n) space, two pointer
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        
        if (x == 0)
            return true;
        
        vector<int> v;
        while (x != 0) {
            v.push_back(x % 10);
            x /= 10;
        }
        
        for (int i = 0, j = v.size() - 1; i < j; ++i, --j) {
            if (v[i] != v[j])
                return false;
        }
        return true;
    }
};


// improvement - O(1) space
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        
        int n = x;
        unsigned int y = 0;
        
        while(n != 0) {
            y = y * 10 + n % 10;
            n /= 10;
        }
        return x == y;
    }
};
