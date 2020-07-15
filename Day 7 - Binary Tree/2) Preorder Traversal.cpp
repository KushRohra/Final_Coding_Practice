//https://leetcode.com/problems/binary-tree-preorder-traversal/

/* Recursive */
class Solution {
public:
    void pre(TreeNode *root, vector<int> &v)
    {
        if(root==NULL)
            return;
        v.push_back(root->val);
        pre(root->left, v);
        pre(root->right, v);
    }
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> v;
        pre(root, v);            
        return v;
    }
};


/* Iterative */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> v;
        if(!root)
            return v;
        stack<TreeNode *> s;
        s.push(root);
        while(s.empty()==false)
        {
            TreeNode *temp=s.top();
            s.pop();
            v.push_back(temp->val);
            if(temp->right)
                s.push(temp->right);
            if(temp->left)
                s.push(temp->left);
        }
        return v;
    }
};
