#include "../Common.h"


class RandomizedSet {
public:
    RandomizedSet() {
        
    }

    bool insert(int val) {
        if (m_.find(val) != m_.end())
            return false;
            
        m_[val] = nums_.size();
        nums_.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (m_.find(val) == m_.end())
            return false;

        // 冒泡
        m_[nums_.back()] = m_[val];
        nums_[m_[val]] = nums_.back();
        nums_.pop_back();
        m_.erase(val);
        return true;
    }

    int getRandom() {
        return nums_[rand() % nums_.size()];
    }

private:
    unordered_map<int, int> m_;
    vector<int> nums_;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */