//https://leetcode.com/problems/symmetric-tree/
class Solution {
public:
    bool solve(TreeNode *t1, TreeNode *t2)
    {
        if(!t1 && !t2)
            return true;
        if(!t1 && t2)
            return false;
        if(!t2 && t1)
            return false;
        return solve(t1->left, t2->right) && solve(t1->right, t2->left) && t1->val==t2->val;
    }
    bool isSymmetric(TreeNode* root) 
    {
        if(!root)
            return true;
        return solve(root->left, root->right);    
    }
};
