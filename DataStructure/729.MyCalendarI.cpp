#include "../Common.h"


class MyCalendar {
public:
    MyCalendar() {
        
    }

    bool book(int start, int end) {
        // 考点：container的lower / upper bound
        // lower_bound -> 返回第一个指向 <= target的iterator
        // upper_bound -> 返回第一个指向 < target的iterator
        map<int, int>::iterator iter = m.upper_bound(start);
        if (iter != m.end() && iter->first < end)
            return false;

        if (iter != m.begin() && (--iter)->second > start)
            return false;

        m[start] = end;
        return true;
    }

private:
    map<int, int> m;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */