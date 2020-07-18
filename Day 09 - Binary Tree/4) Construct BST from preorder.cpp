//https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

/*   O(N^2) approach     */
class Solution {
public:
    TreeNode *construct(TreeNode *root, int x)
    {
        if(!root)
            return root = new TreeNode(x);
        if(root->val>x)
            root->left = construct(root->left, x);
        else root->right = construct(root->right, x);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        TreeNode *root = NULL;
        if(preorder.size()==0)
            return root;
        for (auto x:preorder)
            root = construct(root, x);
        return root;
    }
};


/*  Recusrion Approach   */
class Solution {
public:
    void construct(vector<int> v, int &pos, TreeNode *curr, int left, int right)
    {
        if(pos==v.size() || v[pos]<left || v[pos]>right)
            return;
        if(curr->val>v[pos])
        {
            curr->left = new TreeNode(v[pos]);
            pos+=1;
            construct(v,pos,curr->left,left,curr->val-1);
        }
        if(pos==v.size() || v[pos]<left || v[pos]>right)
            return;
        curr->right = new TreeNode(v[pos]);
        pos+=1;
        construct(v,pos,curr->right,curr->val+1,right);
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        TreeNode *root = NULL;
        int n = preorder.size();
        if(n==0)
            return root;
        root = new TreeNode(preorder[0]);
        if(n==1)
            return root;
        int pos = 1;
        construct(preorder,pos,root,INT_MIN,INT_MAX);
        return root;
    }
};


/*     Stack Approach    */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        stack<TreeNode *> s;
        TreeNode *root;
        root=new TreeNode(preorder[0]);
        s.push(root);
        for(int i=1;i<preorder.size();i++)
        {
            if(s.top()->val>=preorder[i])
            {
                TreeNode *temp=new TreeNode(preorder[i]);
                s.top()->left=temp;
                s.push(temp);
            }
            else
            {
                TreeNode *last;
                while(s.empty()==false && s.top()->val<preorder[i])
                {
                    last=s.top();
                    s.pop();
                }
                TreeNode *temp=new TreeNode(preorder[i]);
                last->right=temp;
                s.push(temp);
            }
        }
        return root;
    }
};
