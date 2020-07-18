//https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
class Solution {
public:
    void flatten(TreeNode* root) 
    {
        TreeNode *temp = root;
        while(temp)
        {
            if(temp->left)
            {
                TreeNode *t = temp->right;
                temp->right = temp->left;
                temp->left = NULL;	//Important
                TreeNode *p = temp;
                while(p && p->right)
                    p = p->right;
                p->right = t;
            }
            temp = temp->right;
        }
        return ;
    }
};
