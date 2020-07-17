//https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
/*  BFS Approach   */
class Solution {
public:
    Node* connect(Node* root)
    {
        queue<Node *> q;
        if(!root)
            return root;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            if(!temp)
            {
                if(q.size()!=0)
                    q.push(NULL);
            }
            else
            {
                temp->next = q.front();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        return root;
    }
};
