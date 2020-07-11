//https://www.interviewbit.com/problems/largest-continuous-sequence-zero-sum/
vector<int> Solution::lszero(vector<int> &A) 
{
    vector<int> ans;
    if(A.size()==0)
        return ans;
    if(A.size()==1 && A[0]!=0)
        return ans;
    int start=-1, last=-1; 
    unordered_map<int, int> m;
    m[0]=-1;
    int sum=0, max_len=-1, len;
    for(int i=0;i<A.size();i++)
    {
        sum+=A[i];
        auto it = m.find(sum);
        if(it!=m.end())
        {
            len=i-m[it->first]+1;
            //cout<<len<<" ";
            if(len>max_len)
            {
                max_len = len;
                start = m[it->first]+1;
                last = i;
            }
        }
        else                        
            m[sum]=i;
    }
    if(last==-1)
        return ans;
    //return ans;
    for(int i=start;i<=last;i++)
        ans.push_back(A[i]);
    return ans;
}

