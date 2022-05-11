#include "../Common.h"


// Implementation 1
class MinStack {
private:
    // 构建另一个栈StackMin，跟随数据本身的Stack同步进退
    vector<int> stack_, min_stack;

public:
    MinStack() {
        min_stack.push_back(INT_MAX);
    }

    void push(int val) {
        stack_.push_back(val);
        min_stack.push_back(min(min_stack.back(), val));
    }
    
    void pop() {
        stack_.pop_back();
        min_stack.pop_back();
    }
    
    int top() {
        return stack_.back();
    }
    
    // 要做到实时得到getMin()，需要对栈内的每一个元素都记录下对应的当前栈内元素最小值
    int getMin() {
        return min_stack.back();
    }
};


// Implementation 2
class MinStack {
private:
    // push delta = x - min0 to the stack
    stack<long> stack_;
    long min_;

public:
    MinStack() {
    }

    void push(int val) {
        if (stack_.empty()) {
            min_ = val;
            stack_.push(0);
        } else {
            stack_.push(val - min_);
            min_ = min(min_, (long) val);
        }
    }

    void pop() {
        if (stack_.top() < 0)
            min_ -= stack_.top();
        stack_.pop();
    }

    int top() {
        int res = min_;
        res += max(stack_.top(), 0L);
        return res;
    }
    
    // 要做到实时得到getMin()，需要对栈内的每一个元素都记录下对应的当前栈内元素最小值
    int getMin() {
        return min_;
    }
};