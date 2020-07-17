//https://leetcode.com/problems/validate-binary-search-tree/

//Due too particular test case the code is diff from the one of GFG
class Solution {
public:
    bool check(TreeNode *root, long min, long max)
    {
        if(!root)
            return true;
        if(root->val<=min || root->val>=max)
            return false;
        return check(root->left, min, root->val) && check(root->right, root->val, max);
    }
    bool isValidBST(TreeNode* root) 
    {
        if(!root)
            return true;
        return check(root, -LONG_MAX, LONG_MAX);    
    }
};
