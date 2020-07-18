//https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1
void helper(Node *root, unordered_set<int> &s, int level)
{
    if(!root)
        return ;
    if(s.find(level)==s.end())
    {
        s.insert(level);
        cout<<root->data<<" ";
    }
    helper(root->left, s, level+1);
    helper(root->right, s, level+1);
}
void leftView(Node *root)
{
    if(!root) return ;
    unordered_set<int> s;
    int level=0;
    helper(root, s, level);
}

