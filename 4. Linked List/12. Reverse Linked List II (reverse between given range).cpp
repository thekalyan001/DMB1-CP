//https://leetcode.com/problems/reverse-linked-list-ii/

//concept is similar to reverse
ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        
       ListNode* dummy=new ListNode(0),*pre=dummy,*curr;
        dummy->next=head;
        for(int i=0;i<m-1;i++){
            pre=pre->next;
        }
        curr=pre->next;
        for(int i=0;i<n-m;i++){
           ListNode* temp=pre->next; //take pointer on current node
           pre->next=curr->next; //make point to next of current
           curr->next=pre->next->next; 
           pre->next->next=temp;
            
        }
        return dummy->next;
    }