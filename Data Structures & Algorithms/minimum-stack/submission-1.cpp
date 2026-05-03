#include <stack>

class MinStack {
public:
    stack<int> stacK; 
    stack<int> minStack; 

    MinStack() {
        stacK = {};
        minStack = {};
    }
    
    void push(int val) {
        stacK.push(val);

        if(minStack.empty() || val <= minStack.top()){
            minStack.push(val);
        }
    }
    
    void pop() {
        if( stacK.top() == minStack.top()){
            stacK.pop();
            minStack.pop();
        }else{
            stacK.pop();
        }
    }
    
    int top() {
       return stacK.top();
    }
    
    int getMin() {
       return minStack.top(); 
    }
};
