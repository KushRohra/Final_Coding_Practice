//https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins/0
#include <bits/stdc++.h>
using namespace std;
int main() 
{
    int t;
    cin>>t;
    vector<int> v={ 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    while(t--)
    {
        i=v.size()-1;
        vector<int> ans;
        int n;
        cin>>n;
        while(i>=0 && n>0)
        {
            //cout<<n<<" ";
            if(n>=v[i])
            {
                ans.push_back(v[i]);
                n-=v[i];
            }
            else i--;
        }
        for(int j=0;j<ans.size();j++)
            cout<<ans[j]<<" ";
        cout<<endl;
    }
}
