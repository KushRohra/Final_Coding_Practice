//https://leetcode.com/problems/add-two-numbers/
class Solution {
public:
    ListNode *head=NULL, *end=NULL;
    void print(ListNode *h)
    {
        while(h)
        {
            cout<<h->val<<" ";
            h=h->next;
        }
        cout<<endl;
    }
    void insert(int val)
    {
        ListNode *temp=new ListNode(val);
        if(!head)
            head=end=temp;
        else
        {
            end->next=temp;
            end=temp;
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        if(!l1) return l2;
        if(!l2) return l1;
        int x, c=0;
        while(l1 && l2)
        {
            x=l1->val+l2->val+c;
            if(x>9)
            {
                x-=10;
                c=1;
            }
            else c=0;
            insert(x);
            l1=l1->next;
            l2=l2->next;
        }
        while(l1)
        {
            x=l1->val+c;
            if(x>9)
            {
                x-=10;
                c=1;
            }
            else c=0;
            insert(x);
            l1=l1->next;
        }
        while(l2)
        {
            x=l2->val+c;
            if(x>9)
            {
                x-=10;
                c=1;
            }
            else c=0;
            insert(x);
            l2=l2->next;
        }
        if(c==1)
            insert(1);
        return head;
    }
};
