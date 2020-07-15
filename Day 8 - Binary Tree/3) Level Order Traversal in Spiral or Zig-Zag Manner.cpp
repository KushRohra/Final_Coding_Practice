//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
class Solution {
public:
    queue<TreeNode *> rev(queue<TreeNode *> q)
    {
        stack<TreeNode *> s;
        while(!q.empty())
        {
            s.push(q.front());
            q.pop();
        }
        while(!s.empty())
        {
            q.push(s.top());
            s.pop();
        }
        return q;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> sol;
        vector<int> temp;
        queue<TreeNode *> q;
        if(!root)
            return sol;
        q.push(root);
        q.push(NULL);
        bool f=1;
        while(!q.empty())
        {
            if(q.front()==NULL)
            {
                q.pop();
                f=!f;
                sol.push_back(temp);
                temp.clear();
                q=rev(q);
                if(q.size()!=0)
                    q.push(NULL);
            }
            else
            {
                TreeNode *t = q.front();
                q.pop();
                temp.push_back(t->val);
                if(!f)
                {
                    if(t->right)
                        q.push(t->right);
                    if(t->left)
                        q.push(t->left);
                }
                else
                {
                    if(t->left)
                        q.push(t->left);
                    if(t->right)
                        q.push(t->right);
                }
            }
        }
        return sol;
    }
};
