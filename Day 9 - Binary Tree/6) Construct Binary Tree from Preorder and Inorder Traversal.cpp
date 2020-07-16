//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
class Solution {
public:
    unordered_map<int, int> m;
    int preIndex;
    TreeNode *build(vector<int> in, vector<int> pre, int start, int end)
    {
        if(start>end)
            return NULL;
        if(preIndex==in.size())
            return NULL;
        int x = pre[preIndex++];
        TreeNode *newNode = new TreeNode(x);
        //if(start==end)
          //  return newNode;
        int Index = m[x];
        newNode->left = build(in, pre, start, Index-1);
        newNode->right = build(in, pre, Index+1, end);
        return newNode;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in)
    {
        m.clear();
        preIndex = 0;
        for(int i=0;i<in.size();i++)
            m[in[i]] = i;
        int start = 0, end = in.size()-1;
        return build(in, pre, start, end);
    }
};
