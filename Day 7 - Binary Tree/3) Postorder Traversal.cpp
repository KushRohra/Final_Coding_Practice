//https://leetcode.com/problems/binary-tree-postorder-traversal/


/* Recursive */
class Solution {
public:
    void post(TreeNode *root, vector<int> &v)
    {
        if(root==NULL)
            return;
        post(root->left, v);
        post(root->right, v);
        v.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> v;
        post(root, v);            
        return v;
    }
};


/* Iterative */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        TreeNode *temp;
        stack<TreeNode *> s1, s2;
        vector<int> v;
        if(!root)
            return v;
        s1.push(root);
        while(!s1.empty())
        {
            temp=s1.top();
            s1.pop();
            s2.push(temp);
            if(temp->left)
                s1.push(temp->left);
            if(temp->right)
                s1.push(temp->right);
        }
        while(!s2.empty())
        {
            v.push_back(s2.top()->val);
            s2.pop();
        }
        return v;
    }
};
