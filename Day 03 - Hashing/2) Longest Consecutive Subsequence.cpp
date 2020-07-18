// https://leetcode.com/problems/longest-consecutive-sequence/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if(nums.size()<=1)
            return nums.size();
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++)
            s.insert(nums[i]);
        int ans = INT_MIN;
        for(auto it=s.begin(); it!=s.end(); it++)
        {
            int temp = *it, c1=0, c2=0;
            while(s.find(temp-1)!=s.end())
            {
                c1++;
                s.erase(temp-1);
                temp-=1;
            }
            temp = *it;
            while(s.find(temp+1)!=s.end())
            {
                c2++;
                s.erase(temp+1);
                temp+=1;
            }
            int len = c1+c2+1;
            ans = max (len, ans);
        }
        return ans;
    }
};
