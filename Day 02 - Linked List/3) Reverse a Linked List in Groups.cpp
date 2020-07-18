//https://leetcode.com/problems/reverse-nodes-in-k-group/
class Solution {
public:
    ListNode *rev(ListNode *head, ListNode *t)
    {
        ListNode *prev=t, *curr=head, *next;
        while(curr)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(!head)
            return head;
        int temp=k-1;
        ListNode *h=head;
        while(temp-- && h->next)
            h=h->next;
        if(temp>=0)
            return head;
        ListNode *next=h->next;
        h->next=NULL;
        next=reverseKGroup(next, k);
        head=rev(head, next);
        return head;
    }
};
