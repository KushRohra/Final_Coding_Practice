//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/


//it is given that both values exist otherwise we would have to confirm 1st if both values exist or not. if not return NULL

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(root->val>p->val && root->val>q->val)
            return lowestCommonAncestor(root->left, p, q);
        else if (root->val<p->val && root->val<q->val)
            return lowestCommonAncestor(root->right, p, q);
        else return root;
    }
};
