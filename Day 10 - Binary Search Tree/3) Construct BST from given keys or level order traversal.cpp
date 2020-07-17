//https://practice.geeksforgeeks.org/problems/convert-level-order-traversal-to-bst/1
Node *build(Node *root, int x)
{
    if(!root)
    {
        Node *temp = new Node(x);
        return temp;
    }
    else if(root->data>x)
        root->left = build(root->left, x);
    else root->right = build(root->right, x);
    return root;
}
Node* constructBst(int arr[], int n)
{
    Node *root = NULL;
    if(n==0)
        return root;
    for(int i=0;i<n;i++)
        root = build(root, arr[i]);
    return root;
}
