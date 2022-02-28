#include "../Common.h"


// priority_queue
class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        pq_left.push(num);
        pq_right.push(-pq_left.top());
        pq_left.pop();

        // rebalance
        if (pq_left.size() < pq_right.size()) {
            pq_left.push(-pq_right.top());
            pq_right.pop();
        }
    }

    double findMedian() {
        return pq_left.size() > pq_right.size() 
            ? pq_left.top() 
            : (pq_left.top() - pq_right.top()) / 2.0;
    }

private:
    // left - max heap 
    priority_queue<int, vector<int>, less<int>> pq_left, pq_right;
    // right - min heap
    // priority_queue<int, vector<int>, greater<int>> pq_right;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
