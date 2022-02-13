//https://leetcode.com/problems/remove-nth-node-from-end-of-list/

int count=0;
        ListNode* temp=head,*pre=NULL;
        while(temp) //count
            temp=temp->next,count++;
        
        if(n==count)//if we've o delete head
        {
            return head->next;
        }
        temp=head; //else
        for(int i=0;i<(count-n);i++)
        {
            pre=temp;
            temp=temp->next;
        }
        pre->next=temp->next;
        return head;
        //time 2* O(n) //n is the number of nodes


M2-

ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *start=new ListNode();
        start->next=head;
        ListNode *slow=start,*fast=start;
        for(int i=0;i<n;i++)
            fast=fast->next;
        
        while(fast->next!=nullptr){
            fast=fast->next;
            slow=slow->next;
        }
        ListNode *del=slow->next;
        slow->next=slow->next->next;
        delete(del);
        return start->next;
    }    


    //time O(n)