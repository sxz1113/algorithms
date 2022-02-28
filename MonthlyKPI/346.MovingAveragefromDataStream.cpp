#include "../Common.h"


class MovingAverage {
public:
    MovingAverage(int size) {
       arr_.resize(size);    
    }
      
    double next(int val) {
        sum_ = sum_ + val - arr_[ptr_ % arr_.size()];
        arr_[ptr_++ % arr_.size()] = val;
        return (double) (sum_) / min(ptr_, (int) (arr_.size()));
    }

private:
    vector<int> arr_;
    int ptr_ = 0;
    long sum_ = 0;
};