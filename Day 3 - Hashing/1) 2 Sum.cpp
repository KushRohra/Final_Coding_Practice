//https://leetcode.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> v;
        if(nums.size()<=1)
            return v;
        unordered_map<int, int> s;
        for(int i=0;i<nums.size();i++)
        {
            int x = target - nums[i];
            auto it = s.find(x);
            if(it!=s.end())
            {
                v.push_back(it->second);
                v.push_back(i);
                return v;
            }   
            else s[nums[i]]=i;
        }
        return v;
    }
};

