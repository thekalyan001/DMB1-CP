 //https://leetcode.com/problems/palindrome-linked-list/

 ListNode* reverse(ListNode* head)
    {
        ListNode *pre=NULL,*next=NULL;
        while(head)
        {
            next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL && head->next==NULL)return true;
        ListNode* slow=head,*fast=head;
        while(fast->next && fast->next->next){
           
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverse(slow->next);
        slow=slow->next;
        while(slow!=NULL)
        {
            if(head->val!=slow->val)
                return false;
            head=head->next;
            slow=slow->next;
        }
        return true;
    }