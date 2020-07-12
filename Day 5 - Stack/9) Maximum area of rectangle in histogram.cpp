//https://leetcode.com/problems/largest-rectangle-in-histogram/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n=heights.size();
        if(n==0)
            return 0;
        if(n==1)
            return heights[0];
        int i, left[n], right[n];
        left[0]=-1;    right[n-1]=n;
        stack<int> sLeft, sRight;
        sLeft.push(0);
        sRight.push(n-1);
        for(i=1;i<n;i++)
        {
            if(sLeft.empty())
                left[i]=0;
            else if(heights[i]>heights[sLeft.top()])
                left[i]=sLeft.top();
            else
            {
                while(!sLeft.empty() && heights[sLeft.top()]>=heights[i])
                    sLeft.pop();
                if(sLeft.empty())
                    left[i]=-1;
                else left[i]=sLeft.top();
            }
            sLeft.push(i);
        }
        for(i=n-2;i>=0;i--)
        {
            if(sRight.empty())
                right[i]=n;
            else if(heights[i]>heights[sRight.top()])
                right[i]=sRight.top();
            else
            {
                while(!sRight.empty() && heights[sRight.top()]>=heights[i])
                    sRight.pop();
                if(sRight.empty())
                    right[i]=n;
                else right[i]=sRight.top();
            }
            sRight.push(i);
        }
        int ans=INT_MIN;
        for(i=0;i<n;i++)
        {
            int temp=right[i]-left[i]-1;
            temp*=heights[i];
            ans=max(ans, temp);
        }
        return ans;
        
    }
};
