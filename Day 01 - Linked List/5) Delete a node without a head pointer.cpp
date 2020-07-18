//https://leetcode.com/problems/delete-node-in-a-linked-list/submissions/
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *prev=node;
        while(node->next!=NULL)
        {
           // cout<<node->val<<" ";
            node->val=node->next->val;
            //cout<<node->val<<" \n";
            prev=node;
            node=node->next;
        }
        prev->next=prev->next->next;
    }
};
