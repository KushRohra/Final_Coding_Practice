//https://leetcode.com/problems/same-tree/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if(!p && !q)
            return true;
        if(p && !q)
            return false;
        if(!p && q)
            return false;
        return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right) && p->val==q->val);  
    }
};
