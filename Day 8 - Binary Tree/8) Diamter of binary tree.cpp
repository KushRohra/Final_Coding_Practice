//https://leetcode.com/problems/diameter-of-binary-tree/
class Solution {
public:
    int height(TreeNode *root, int &res)
    {
        if(!root)
            return 0;
        int lh = height(root->left, res);
        int rh = height(root->right, res);
        int temp = max(lh+rh+1, max(lh, rh)+1);
        res = max(res, temp);
        return max(lh,rh)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        if(!root)
            return 0;
        int res = INT_MIN;
        height(root, res);
        return res-1;
    }
};
