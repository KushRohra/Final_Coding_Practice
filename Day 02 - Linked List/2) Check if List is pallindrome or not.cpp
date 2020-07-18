//https://leetcode.com/problems/palindrome-linked-list/
class Solution {
public:
    ListNode *rev(ListNode *head)
    {
        ListNode *curr=head, *prev=NULL, *next;
        while(curr)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) 
    {
        ListNode *slow=head, *fast=head, *temp=head;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *t=slow;
        slow=rev(slow);
        while(temp!=t)
        {
            if(temp->val!=slow->val)
                return 0;
            temp=temp->next;
            slow=slow->next;
        }
        return 1;
    }
};
