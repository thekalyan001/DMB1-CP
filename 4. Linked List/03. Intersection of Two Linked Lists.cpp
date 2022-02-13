//https://leetcode.com/problems/intersection-of-two-linked-lists/

method1
  count1 the length of list1
  count2 the length of list2

  if(coutn1>count2)
    traverse list1 for(int i=0;i<(count1-count2);i++)
  else if(count2>count1)
    traverse list2 for(int i=0;i<(count2-count1);i++)

  then start traversing both the linkd list ek pointer will be start from suru and dusra from difference of count distance

  Time O(2*(m+n)) ek baar length calculate ek baar intersection




M2-

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptr1=headA,*ptr2=headB; //take two pointers
        if(headA==NULL or headB==NULL) return NULL; //check base case
        
        while(ptr1!=ptr2){
            ptr1= ptr1==NULL?headA:ptr1->next; //assign to head of other LL if it become null
            ptr2= ptr2==NULL?headB:ptr2->next; //same as above
        }
        return ptr1; //when both pointers matches then return
    }

    O(m+n)