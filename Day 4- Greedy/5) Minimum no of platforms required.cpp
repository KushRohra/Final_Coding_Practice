//https://practice.geeksforgeeks.org/problems/minimum-platforms/0
#include <bits/stdc++.h>
using namespace std;
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int i, n, x;
        cin>>n;
        multimap<int, bool> m;
        for(i=0;i<2*n;i++)
        {
            cin>>x;
            if(i<n)
                m.insert(make_pair(x,0));
            else m.insert(make_pair(x,1));
        }
        int ans=-1, k=0;
        for(auto it=m.begin();it!=m.end();it++)
        {
            if(it->second==0)
                k++;
            else k--;
            ans = max(ans, k);
        }
        cout<<ans<<endl;
    }
}
