https://leetcode.com/problems/reverse-nodes-in-k-group/

//O(1)for iterative solution
ListNode* reverseKGroup(ListNode* head, int k) {
   if(head==NULL or head->next==NULL && k==1)return head;
   ListNode *dummy=new ListNode(0);
   dummy->next=head;
   ListNode *curr=dummy,*pre=dummy,*nex=dummy;

   int count=0;
   while(curr->next!=NULL)
   {
       count++;curr=curr->next;
   }
         while(count>=k) //count<k then dont reverse any elenent
         {
            curr=pre->next; //first k wala node
            nex=curr->next;
            for(int i=1;i<k;i++)
            {

                curr->next=nex->next;
                nex->next=pre->next;
                pre->next=nex;
                nex=curr->next;
            }
            pre=curr;
            count-=k;
        }
        return dummy->next;




         //using recursion



         //O(n)space for recursion stack
         ////agar <k elements hai then don't reverse | koi question me rhe ki krna h rev then remove this line
        
ListNode* reverseKGroup(ListNode* head, int k) {
           if(head==NULL or head->next==NULL && k==1)return head;
           ListNode* cursor = head;
           for(int i = 0; i < k; i++){ 
            if(cursor == nullptr) return head;
            cursor = cursor->next;
        }


        ListNode* curr=head,*pre=NULL,*next=NULL;
        int i=0;
        while(curr!=NULL && i<k)
        {
           i++;
             //reverse k elements and call for next set
           next=curr->next;
           curr->next=pre;
           pre=curr;
           curr=next;
       }
       if(next!=NULL)
        head->next=reverseKGroup(curr,k);
    return pre;
}