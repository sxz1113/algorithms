#include "../Common.h"


/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 */
class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};


/** Solution I
 * @brief Idea: DFS - store pointers into stack
 * Example 2: nestedList = [1,[4,[6]]] -- nested lsit -- gives me ideas of DFS

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        // push pointers to nestedInteger onto stack
        for (int i = nestedList.size() - 1; i >= 0; --i) {
            stk_.push(&nestedList[i]);
        }
    }
    
    int next() {
        int next_int = stk_.top()->getInteger();
        stk_.pop();
        return next_int;
    }
    
    bool hasNext() {
        // use DFS to flatten current level
        while (!stk_.empty()) {
            NestedInteger *i = stk_.top();
            // if NestedInteger holds a single integer, we do have next element
            if (i->isInteger())
                return true;

            // if NestedInteger holds a nsted list, check if the nested list is empty
            stk_.pop();
            vector<NestedInteger> &arr_list = i->getList();
            for (int j = arr_list.size() - 1; j >= 0; --j)
                stk_.push(&arr_list[j]);
        }
        return false;
    }

private:
    stack<NestedInteger*> stk_;
};
*/

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */


/**
 * @brief Solution 2, push iterators onto stack
 * 
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        // persist begin and end iterators of the vector
        it_begin.push(nestedList.begin());
        it_end.push(nestedList.end());
    }
    
    int next() {
        return it_begin.top()++ -> getInteger();
    }
    
    bool hasNext() {
        // use DFS to flatten current level
        while (!it_begin.empty()) {
            vector<NestedInteger>::iterator cur = it_begin.top();
            
            // check if iterator has reached the end of current level
            if (cur == it_end.top()) {
                it_begin.pop();
                it_end.pop();
                continue;
            }

            // if NestedInteger holds a single integer, we do have next element
            if (cur->isInteger())
                break;

            // if NestedInteger holds a nsted list, check if the nested list is empty
            // advance iterator
            it_begin.top()++;
            it_begin.push(begin(cur->getList()));
            it_end.push(end(cur->getList()));
        }

        return !it_begin.empty();
    }

private:
    stack<vector<NestedInteger>::iterator> it_begin, it_end;
};


// initialize iterator with nestedList
// res = []
// while iterator.hasNext()
//     append iterator.next() to the end of res
// return res