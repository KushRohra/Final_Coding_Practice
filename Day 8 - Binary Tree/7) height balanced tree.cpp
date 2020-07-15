//https://leetcode.com/problems/balanced-binary-tree/
class Solution {
public:
    int checker(TreeNode *root, bool &ans)
    {
        if(!root)
            return 0;
        int lh = checker(root->left, ans)+1;
        int rh = checker(root->right, ans)+1;
        //cout<<root->val<<" "<<lh<<" "<<rh<<endl;
        if(abs(lh-rh)>1)
            ans =ans && false;
        else ans = ans && true;
        return max(lh, rh);
    }
    bool isBalanced(TreeNode* root)
    {
        bool ans = true;
        checker(root, ans);
        return ans;
    }
};
