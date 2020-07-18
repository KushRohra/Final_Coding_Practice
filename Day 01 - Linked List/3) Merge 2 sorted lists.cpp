//https://leetcode.com/problems/merge-two-sorted-lists/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        int x;
        ListNode *head=NULL, *end=NULL;
        if(!l1) return l2;
        if(!l2) return l1;
        while(l1 && l2)
        {
            if(l1->val<l2->val)
            {
                x=l1->val;
                l1=l1->next;
            }
            else
            {
                x=l2->val;
                l2=l2->next;
            }
            ListNode *temp=new ListNode(x);
            if(!head)
            {
                head=end=temp;
            }
            else
            {
                end->next=temp;
                end=temp;
            }
        }
        while(l1)
        {
            ListNode *temp=new ListNode(l1->val);
            end->next=temp;
            end=temp;
            l1=l1->next;
        }
        while(l2)
        {
            ListNode *temp=new ListNode(l2->val);
            end->next=temp;
            end=temp;
            l2=l2->next;
        }
        return head;
    }
};
