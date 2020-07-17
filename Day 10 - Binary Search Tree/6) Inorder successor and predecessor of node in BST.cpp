//https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if(!root)
        return ;
    if(root->key==key)
    {
        Node *temp;
        if(root->left!=NULL)
        {
            temp = root->left;
            while(temp->right)
                temp = temp->right;
            pre = temp;
        }
        if(root->right!=NULL)
        {
            temp = root->right;
            while(temp->left)
                temp = temp->left;
            suc = temp;
        }
        return ;
    }
    if(root->key>key)
    {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
    else 
    {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
}
