//https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room/0
#include <bits/stdc++.h>
using namespace std;
struct job{
    int st, et, index;
    bool type;
};
bool comp(job &a, job &b)
{
    if(a.et==b.et)
        return a.index<b.index;
    return a.et<b.et;
}
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, i;
        cin>>n;
        int start[n], end[n];
        for(i=0;i<n;i++)
            cin>>start[i];
        for(i=0;i<n;i++)
            cin>>end[i];
        vector<job> v; 
        for(i=0;i<n;i++)
        {
            job p;
            p.st=start[i];
            p.et=end[i];
            p.index=i+1;
            v.push_back(p);
        }
        sort(v.begin(), v.end(), comp);
        //for(i=0;i<v.size();i++)
           // cout<<v[i].st<<" "<<v[i].et<<" "<<v[i].index<<endl;
        int j=0;
        for(i=0;i<v.size();i++)
        {
            if(i==0)
                cout<<v[i].index<<" ";
            else if(v[i].st>=v[j].et)
                cout<<v[i].index<<" ", j=i;
        }
        cout<<endl;
    }
}
