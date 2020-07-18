//https://leetcode.com/problems/binary-tree-right-side-view/
class Solution {
public:
    void helper(TreeNode *root, unordered_map<int, int> &m, int level, int &maxLevel)
    {
        if(!root)
            return ;
        helper(root->left, m, level+1, maxLevel);
        maxLevel = max(level, maxLevel);
        m[level] = root->val;
        helper(root->right, m, level+1, maxLevel);
    }
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> empty;
        if(!root)
            return empty;
        unordered_map<int, int> m;
        int level=0, maxLevel=0;
        helper(root, m, level, maxLevel);
        vector<int> v(maxLevel+1, 0);
        for(auto it=m.begin();it!=m.end();it++)
            v[it->first] = it->second;
        return v;
    }
};
