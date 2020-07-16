//https://leetcode.com/problems/binary-tree-maximum-path-sum/
class Solution {
public:
    int solve(TreeNode *root, int &ans)
    {
        if(!root)
            return 0 ;
        int lh = solve(root->left, ans);
        int rh = solve(root->right, ans);
        ans = max(ans, max(max(lh+rh+root->val, max(lh, rh)+root->val), root->val));
        return max(max(lh, rh)+root->val, root->val);
    }
    int maxPathSum(TreeNode* root) 
    {
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
};
