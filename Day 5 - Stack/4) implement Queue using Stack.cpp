//https://leetcode.com/problems/implement-queue-using-stacks/
class MyQueue {
public:
    /** Initialize your data structure here. */
    vector<int> q;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        q.push_back(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x = q[0];
        q.erase(q.begin());
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        return q[0];
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return !q.size();
    }
};
