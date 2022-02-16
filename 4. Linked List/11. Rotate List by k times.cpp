//https://leetcode.com/problems/rotate-list/

ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0)return head;
        ListNode* curr=head;
        int count=1;
        while(curr->next)
            curr=curr->next,count++;
        
        curr->next=head;
        k=count-k%count; //% to avoid double traversal
        while(k--)
            curr=curr->next;
        
        head=curr->next;
        curr->next=nullptr;
        return head;
    }