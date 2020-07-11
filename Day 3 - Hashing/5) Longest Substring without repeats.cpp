//https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_map<int, bool> v;
        int left=0, right=0, maxLen=1;
        if(s.length()<2)
            return s.length();
        while(left<s.length() && right<s.length())
        {
            //cout<<left<<" "<<right<<endl;
            if(v[s[right]-'a']==0)
            {
                v[s[right]-'a']=1;
                right++;
            }
            else 
            {
                while(left<s.length() && v[s[right]-'a']==1)
                {
                    v[s[left]-'a']=0;
                    left++;
                }
                v[s[right]-'a']=1;
                right++;
            }
            if(right-left>maxLen)
                maxLen=right-left;
        }
        return maxLen;
    }
};
