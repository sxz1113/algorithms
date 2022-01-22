#include "Common.h"


// hashmap
class SolutionHashmap {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int num : nums) {
            if (m.find(num) == m.end())
                return true;
            else
                m[num] = 1;

        }
        return false;
    }
};


// set
class SolutionSet {
public:
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() > set(nums.begin(), nums.end()).size();
    }
};