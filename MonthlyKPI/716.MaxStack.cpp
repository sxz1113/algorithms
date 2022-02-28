#include "../Common.h"


class MaxStack {
public:

    int cnt;
    map<int, int, greater<int>> stk;
    map<int, stack<int>, greater<int>> max_stk;
    
    void push(int x) 
    {
        stk.insert({cnt, x});
        max_stk[x].push(cnt);
        cnt++;
    }
    
    int pop() 
    {
        auto x = *stk.begin();
        stk.erase(stk.begin());
        max_stk[x.second].pop();
        if(max_stk[x.second].empty())
        {
            max_stk.erase(x.second);
        }
        return x.second;
    }
    
    int top() 
    {
        return (*stk.begin()).second;
    }
    
    int peekMax() 
    {
        return (*max_stk.begin()).first;
    }
    
    int popMax() 
    {
        auto x = *max_stk.begin();
        stk.erase(x.second.top());
        max_stk[x.first].pop();
        if(max_stk[x.first].empty())
        {
            max_stk.erase(x.first);
        }
        return x.first;
    }
};