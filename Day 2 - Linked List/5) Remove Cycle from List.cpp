class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        ListNode *slow=head, *fast=head;
        while(slow && fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                slow=head;
                while(slow->next!=fast->next)
                {
                    slow=slow->next;
                    fast=fast->next;
                }
                slow->next=NULL;
            }
        }
        return head;
    }
};
