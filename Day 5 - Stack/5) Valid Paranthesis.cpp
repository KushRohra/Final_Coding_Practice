//https://leetcode.com/problems/valid-parentheses/
class Solution {
public:
    char geteq(char x)
    {
        switch(x)
        {
            case ')': return '(';
            case '}': return '{';
            case ']': return '[';
        }
        return '1';
    }
    bool isValid(string A)
    {
        stack<char> s;
        for(int i=0;i<A.length();i++)
        {
            if(A[i]=='(' || A[i]=='{' || A[i]=='[')
                s.push(A[i]);
            else 
            {
                char x = geteq(A[i]);
                if(s.empty())
                    return 0;
                if(s.empty()==false && x!=s.top())
                    return 0;
                else s.pop();
            }
        }
        if(s.empty()==false)
            return 0;
        return 1;
    }
};
