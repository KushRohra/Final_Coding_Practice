//https://leetcode.com/problems/intersection-of-two-linked-lists/
class Solution {
public:
    int len(ListNode *head)
    {
        int c=0;
        while(head)
        {
            c++;
            head=head->next;
        }
        return c;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        int c1=len(headA), c2=len(headB), d;
        ListNode *curr=headB, *other=headA;
        if(c1>c2)
        {
            d=c1-c2;
            curr=headA;
            other=headB;
        }
        else d=c2-c1;
        while(d--)
            curr=curr->next;
        while(curr && other && curr!=other)
        {
            curr=curr->next;
            other=other->next;
        }
        if(curr==other)
            return curr;
        return NULL;
    }
};
