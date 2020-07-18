//https://practice.geeksforgeeks.org/problems/next-larger-element/0
#include <bits/stdc++.h>
using namespace std;
int main() 
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int n,i;
        cin>>n;
        long long int a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        stack<long long int> s;
        for(i=n-1;i>=0;i--)
        {
            long long int x=a[i];
            if(s.empty())
                a[i]=-1;
            else if(a[i]<s.top())
                a[i]=s.top();
            else
            {
                while(!s.empty() && s.top()<=a[i])
                    s.pop();
                if(s.empty())
                    a[i]=-1;
                else a[i]=s.top();
            }
            s.push(x);
        }
        for(i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
}
