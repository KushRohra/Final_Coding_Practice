// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

vector <int> bfs(vector<int> g[], int N);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        vector<int> adj[N];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        vector <int> res = bfs(adj, N);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        cout << endl;
    }
}// } Driver Code Ends


/* You have to complete this function*/

/* Function to do BFS of graph
*  g[]: adj list of the graph
*  N : number of vertices
*/
vector <int> bfs(vector<int> g[], int N) 
{
    vector<bool> vis(N,0);
    int src=0;
    vector<int> v;
    queue<int> q;
    q.push(src);
    vis[src]=1;
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        v.push_back(temp);
        for(int i=0;i<g[src].size();i++)
            if(!vis[g[src][i]])
            {
                q.push(g[src][i]);
                vis[g[src][i]]=1;
            }
    }
    return v;
}

















