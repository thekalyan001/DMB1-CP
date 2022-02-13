ListNode* reverseList(ListNode* head) {
        ListNode* p=head,*q=NULL,*r=NULL;
        while(p!=NULL)
        {
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }return q;
    }