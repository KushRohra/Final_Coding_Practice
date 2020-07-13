//https://leetcode.com/problems/sliding-window-maximum/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) 
    {
        deque<int> q;
        int i=0;
        vector<int> v;
        for(;i<k;i++)
        {
            while(!q.empty() && a[i]>=a[q.back()])
                q.pop_back();
            q.push_back(i);
        }
        for(;i<a.size();i++)
        {
            v.push_back(a[q.front()]);
            while(!q.empty() && q.front()<=i-k)
                q.pop_front();
            while(!q.empty() && a[i]>=a[q.back()])
                q.pop_back();
            q.push_back(i);
        }
        v.push_back(a[q.front()]);
        return v;
    }
};

