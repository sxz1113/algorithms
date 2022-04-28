#include "../Common.h"


/*
class SummaryRanges {
public:
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        // 采用lazy evaluate / 拖延症处理方式，先丢进set
        s.insert(val);
    }
    
    vector<vector<int>> getIntervals() {
        // 遍历s，不断更新start和end。
        // 当集合元素i != end + 1时，就可以根据start / end生成一个区间；
        // 同时更新 start = a, end = a
        vector<vector<int>> intervals;
        auto iter = s.begin();
        int start = *iter, end = *iter;

        while (iter != s.end()) {
            ++iter;
            if (*iter == end + 1) {
                ++end;
            } else {
                intervals.push_back({start, end});
                start = *iter;
                end = *iter;
            }
        }

        intervals.push_back({start, end});
        return intervals;
    }

private:
    set<int> s;
};
*/


class SummaryRanges {
public:
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        // 加入num时候就前处理，不拖延
        auto hi = kv.lower_bound(val);
        auto lo = (hi == kv.end()) ? kv.end() : prev(hi, 1);

        if (lo != kv.end() && hi != kv.end() && 
            lo->second + 1 == val && hi->first == val + 1) {
            lo->second = hi->second;
            kv.erase(hi);
        } else if (lo != kv.end() && lo->second + 1 >= val) {
            lo->second = max(lo->second, val);
        } else if (hi != kv.end() && hi->first - 1 == val) {
            kv[val] = hi->second;
            kv.erase(hi);
        } else {
            kv[val] = val;
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (const auto &item : kv) {
            res.emplace_back(vector<int>{item.first, item.second});
        }
        return res;
    }

private:
    map<int, int> kv;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */