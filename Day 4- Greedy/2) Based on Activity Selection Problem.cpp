//https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
/*
	Based on Activity Selection Problem
*/
class Solution {
public:
    struct balloons{
        int sp, ep;
    };
    static bool comp(balloons &a, balloons &b)
    {
        return a.ep<b.ep;
    }
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        int i, n=points.size();
        if(n==0)
            return 0;
        vector<balloons> v;
        balloons p;
        for(i=0;i<n;i++)
        {
            p.sp=points[i][0];
            p.ep=points[i][1];
            v.push_back(p);
        }
        sort(v.begin(), v.end(), comp);
        int c=1, j=0;
        for(i=1;i<n;i++)
        {
            if(v[i].sp>v[j].ep)
            {
                c++;
                j=i;
            }
        }
        return c;
    }
};
