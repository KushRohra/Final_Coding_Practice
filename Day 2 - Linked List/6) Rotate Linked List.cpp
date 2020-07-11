//https://leetcode.com/problems/rotate-list/
class Solution {
public:
    int len(ListNode *head)
    {
        int c=0;
        while(head)
        {
            head=head->next;
            c++;
        }
        return c;
    }
    ListNode* rotateRight(ListNode* head, int k)
    {
        if(!head)
            return head;
        int c=len(head);
        k=k%c;
        if(k==0)
            return head;
        int d=c-k-1;
        ListNode *temp=head, *end=temp;
        while(end->next)
            end=end->next;
        end->next=head;
        while(d--)
            temp=temp->next;
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};
