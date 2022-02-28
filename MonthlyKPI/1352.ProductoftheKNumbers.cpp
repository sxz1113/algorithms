#include "../Common.h"


// prefix array
class ProductOfNumbers {
public:
    ProductOfNumbers() {
    }
    
    void add(int num) {
        if (num == 0)
            prefix = { 1 };
        else
            prefix.push_back(prefix.back() * num);
    }
    
    int getProduct(int k) {
        return (k > prefix.size()) ? 
            0 : prefix.back() / prefix[prefix.size() - k - 1];
    }

private:
    vector<int> prefix { 1 };
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */