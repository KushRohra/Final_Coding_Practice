#include<bits/stdc++.h>
using namespace std;
struct items{
    int weight, profit;
    float ratio;
};
bool comp(items &a, items &b)
{
    return a.ratio>b.ratio;
}
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        vector<items> v;
        items item;
        int n,i,capacity,p,w;
        cin>>n>>capacity;
        for(i=0;i<n;i++)
        {
            cin>>p>>w;
            item.profit = p;
            item.weight = w;
            item.ratio = (float)p/w;
            v.push_back(item);
        }
        sort(v.begin(), v.end(), comp);
        i=0;
        float profit = 0;
        while(i<n && capacity>0)
        {
            if(v[i].weight<=capacity)
            {
                profit+=v[i].profit;
                capacity-=v[i].weight;
                i++;
            }
            else
            {
                profit+=(float)v[i].profit*((float)capacity/(float)v[i].weight);
                capacity=0;
            }
        }
        cout<<profit<<endl;
    }
}
