//https://leetcode.com/problems/min-stack/
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s, min;
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        if(min.empty())
        {
            min.push(x);
            return ;
        }
        if(x<min.top())
            min.push(x);
        else min.push(min.top());
    }
    
    void pop() {
        s.pop();
        min.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return s.empty() ? -1 : min.top();
    }
};

