//https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1
void find(Node *root, int target, vector<int> temp, vector<int> &path)
{
    if(!root || path.size()!=0)
        return ;
    temp.push_back(root->data);
    if(root->data==target)
        path = temp;
    find(root->left, target, temp, path);
    find(root->right, target, temp, path);
}
int kthAncestor(Node *root, int k, int node)
{
    if(!root)
        return -1;
    vector<int> temp, path;
    find(root, node, temp, path);
    if(k<0 || k>path.size()-1)
        return -1;
    return path[path.size()-k-1];
}

