#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <vector>

using namespace std;

int fib(int n) {
    vector<int> res { 0, 1 };
    for (int i = 2; i <= n; ++i) {
        res.push_back(res[i - 1] + res[i - 2]);
    }
    return res[n];
}


int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);
    cout << "The " << n << "th fibonacci number is " << fib(n) << endl;
}
