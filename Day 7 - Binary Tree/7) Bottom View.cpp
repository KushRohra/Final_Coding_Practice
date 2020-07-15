//https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
vector <int> bottomView(Node *root)
{
    vector<int> v;
   if(!root)
        return v;
    map<int, int> m;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while(!q.empty())
    {
        Node *temp = q.front().first;
        int x = q.front().second;
        q.pop();
        m[x] = temp->data;
        if(temp->left)
            q.push({temp->left, x-1});
        if(temp->right)
            q.push({temp->right, x+1});
    }
    for(auto it=m.begin();it!=m.end();it++)
        v.push_back(it->second);
    return v;
}
