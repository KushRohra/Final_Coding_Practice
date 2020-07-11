//https://practice.geeksforgeeks.org/problems/job-sequencing-problem/0
#include <bits/stdc++.h>
using namespace std;
struct job{
    int id, deadline, profit;
};
bool comp(job &a, job &b)
{
    return a.profit>b.profit;
}
int find(int x, vector<int> jobs)
{
    if(x==jobs[x])
        return x;
    return find(jobs[x],jobs);
}
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,x,z,y,maxDeadline=INT_MIN;
        cin>>n;
        job p;
        vector<job> v;
        for(i=0;i<n;i++)
        {
            cin>>x>>y>>z;
            p.id=x;
            p.deadline=y;
            p.profit=z;
            maxDeadline=max(maxDeadline,z);
            v.push_back(p);
        }
        vector<int> jobs;
        for(i=0;i<=maxDeadline;i++)
            jobs.push_back(i);
        int total=0, c=0;
        sort(v.begin(), v.end(), comp);
        for(i=0;i<n;i++)
        {
            x=find(v[i].deadline,jobs);
            //cout<<i<<" "<<x<<" ";
            if(x>0)
            {
                c++;
                total+=v[i].profit;
                jobs[x]=find(x-1,jobs);
            }
        }
        cout<<c<<" "<<total<<endl;
    }
}
