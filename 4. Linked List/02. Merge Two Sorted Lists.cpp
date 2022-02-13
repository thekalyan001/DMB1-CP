//https://leetcode.com/problems/merge-two-sorted-lists/

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(INT_MIN);
        ListNode* res=&dummy;
        
        while(list1 && list2)
        {
            if(list1->val<=list2->val)
            {
                res->next=list1;
                list1=list1->next;
            }
            else
            {
                res->next=list2;
                list2=list2->next;
            }
            res=res->next;
        }
        res->next=list1?list1:list2;
        return dummy.next;
}
time O(n+m) space o(1)

/*  Using Recursion */

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* res;
        if(list1==NULL)return list2;
        if(list2==NULL)return list1;
        
       if(list1->val<=list2->val)
       {
           res=list1;
           res->next=mergeTwoLists(list1->next,list2);
       }
        else
        {
            res=list2;
            res->next=mergeTwoLists(list1,list2->next);
            
        }
            return res;
}

time O(n+m) space O(n)