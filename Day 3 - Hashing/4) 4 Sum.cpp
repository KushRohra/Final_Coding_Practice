//https://leetcode.com/problems/4sum
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int>> v;
        if(nums.size()<4)
            return v;
        sort(nums.begin(), nums.end());
        unordered_map<int, pair<int, int>> m;
        for(int i=0;i<nums.size()-1;i++)
            for(int j=i+1;j<nums.size();j++)
                m[nums[i]+nums[j]]={i, j};
        for(int i=0;i<nums.size()-3;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            for(int j=i+1;j<nums.size()-2;j++)
            {
                if(j>1 && nums[j]==nums[j-1] && j-i>1)
                    continue;
                int k=j+1, l=nums.size()-1;
                while(k<l)
                {
                    if(nums[i]+nums[j]+nums[k]+nums[l]-target==0)
                    {
                        v.push_back({nums[i], nums[j], nums[k], nums[l]});
                        while(k+1<l-1 && nums[k]==nums[k+1] && nums[l]==nums[l-1])
                        {
                            k++;
                            l--;
                        }
                        k++;
                        l--;
                    }
                    else if(nums[i]+nums[j]+nums[k]+nums[l]-target>0)
                        l--;
                    else k++;
                        
                }
            }
        }
        return v;
    }
};
