/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode *second=head, *first=head;
        while(n--)
            second=second->next;
        if(!second)
        {
            head=head->next;
            return head;
        }
        while(second->next!=NULL)
        {
            first=first->next;
            second=second->next;
        }
        first->next=first->next->next;
        return head;
    }
};
