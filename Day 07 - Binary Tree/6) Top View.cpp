//https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
void topView(struct Node *root)
{
    if(!root)
        return ;
    map<int, int> m;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while(!q.empty())
    {
        Node *temp = q.front().first;
        int x = q.front().second;
        q.pop();
        if(m.find(x)==m.end())
            m[x] = temp->data;
        if(temp->left)
            q.push({temp->left, x-1});
        if(temp->right)
            q.push({temp->right, x+1});
    }
    for(auto it=m.begin();it!=m.end();it++)
        cout<<it->second<<" ";
}

