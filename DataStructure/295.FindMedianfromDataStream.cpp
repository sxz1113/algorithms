#include "../Common.h"


class MedianFinder {
public:
    // 使用multiset & its iterator， maintain iterator的位置
    MedianFinder() {
        iter_ = s_.begin();
        res_ = *iter_;
    }
    
    void addNum(int num) {
        s_.insert(num);
        if (s_.size() % 2 == 1) {
            if (num >= *iter_)
                iter_ = next(iter_, 1);

            res_ = *iter_;
        } else {
            if (num < *iter_)
                iter_ = prev(iter_, 1);

            res_ = *iter_ / 2 + *(next(iter_, 1)) / 2;
        }
    }
    
    double findMedian() {
        return res_;
    }

private:
    double res_;
    multiset<int> s_;
    multiset<int>::iterator iter_;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
