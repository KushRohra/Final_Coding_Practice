//https://leetcode.com/problems/binary-tree-inorder-traversal/


/* Recursive */
class Solution {
public:
    void inorder(TreeNode *root, vector<int> &v)
    {
        if(!root)
            return ;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> v;
        inorder(root, v);
        return v;
    }
};


/* Iterative */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> v;
        if(root==NULL)
            return v;
        stack<TreeNode *> s;
        TreeNode *curr=root;
        while(curr!=NULL || s.empty()==false)
        {
            while(curr)
            {
                s.push(curr);
                curr=curr->left;
            }
            curr=s.top();
            s.pop();
            v.push_back(curr->val);
            curr=curr->right;
        }
        return v;
    }
};
