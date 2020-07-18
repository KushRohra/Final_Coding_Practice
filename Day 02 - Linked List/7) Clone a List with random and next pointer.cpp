//https://leetcode.com/problems/copy-list-with-random-pointer/
class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        if(!head)
            return NULL;
        Node *copyHead=NULL, *temp=head, *next;
        while(temp)
        {
            Node *t=new Node(temp->val);
            if(!copyHead)
                copyHead=t;
            next=temp->next;
            t->next=next;
            temp->next=t;
            temp=next;
        }
        temp=head;
        while(temp)
        {
            if(temp->random!=NULL)  
                temp->next->random = temp->random->next;
            else temp->next->random = NULL;
            temp = temp->next->next;
        }
        temp=head;
        while(temp)
        {
            Node *p=temp->next->next;
            if(temp->next->next!=NULL)
                temp->next->next = temp->next->next->next;
            else
                temp->next->next = NULL;
            temp->next=p;
            temp=temp->next;
        }
        return copyHead;
    }
};
