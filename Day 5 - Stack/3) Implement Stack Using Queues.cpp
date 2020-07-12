//https://leetcode.com/problems/implement-stack-using-queues/
class MyStack {
public:
    /** Initialize your data structure here. */
    vector<int> st;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        st.push_back(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = st[st.size()-1];
        st.pop_back();
        return x;
    }
    
    /** Get the top element. */
    int top() {
        return st[st.size()-1];
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return !st.size();
    }
};
