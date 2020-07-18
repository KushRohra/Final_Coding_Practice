//https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
class Solution {
public:
    unordered_map<int, int> m;
    int postIndex;
    TreeNode *build(vector<int> in, vector<int> post, int start, int end)
    {
        if(start>end)
            return NULL;
        if(postIndex<0)
            return NULL;
        int x = post[postIndex];
        postIndex--;
        TreeNode *newNode = new TreeNode(x);
        if(start==end)
            return newNode;
        int Index = m[x];
        newNode->right = build(in, post, Index+1, end);
        newNode->left = build(in, post, start, Index-1);
        return newNode;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) 
    {
        m.clear();
        postIndex = in.size()-1;
        for(int i=0;i<in.size();i++)
            m[in[i]] = i;
        int start = 0, end = in.size()-1;
        return build(in, post, start, end);        
    }
};
