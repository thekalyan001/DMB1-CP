// for (auto p = head; p != nullptr; p = p->next) {
//https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
ListNode* swapNodes(ListNode* head, int k) {
        ListNode *p=head,*q=head;
        int n=0;
        while(p!=NULL){
            n++;p=p->next;
        }
        
        p=head;
        for(int i=0;i<n-k;i++){
            p=p->next;
        }
        k--;
        while(k--){
            q=q->next;
        }
        cout<<p->val<<" "<<q->val<<endl;
        swap(p->val,q->val);
        return head;
    }
    //method 2
ListNode* swapNodes(ListNode* head, int k) {
    ListNode *p1 = head;
    for(int i=1; i<k; i++)
        p1 = p1->next;
    
    ListNode *slow = head, *fast = p1->next;
    while(fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    
    swap(slow->val, p1->val);
    return head;
}