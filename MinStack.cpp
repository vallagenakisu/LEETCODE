#include<bits/stdc++.h>
using namespace std;
class MinStack {
private:
    stack<int> stk;
    int mn_val = INT_MAX;
    stack<int> prefix_min;
public:
    MinStack() {
        
    }
   void push(int val) {
        stk.push(val);
        if (prefix_min.empty()) {
            prefix_min.push(val);
        } else {
            prefix_min.push(min(prefix_min.top(), val));
        }
    }
    
    void pop() {
        stk.pop();
        prefix_min.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return prefix_min.top();
    }
};
