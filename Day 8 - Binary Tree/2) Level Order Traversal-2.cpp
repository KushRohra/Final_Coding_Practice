//https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> sol;
        vector<int> temp;
        queue<TreeNode *> q;
        if(!root)
            return sol;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            if(q.front()==NULL)
            {
                q.pop();
                sol.push_back(temp);
                temp.clear();
                if(q.size()!=0)
                    q.push(NULL);
            }
            else
            {
                TreeNode *t = q.front();
                q.pop();
                temp.push_back(t->val);
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
        }
        reverse(sol.begin(), sol.end());
        return sol;
    }
};
