//https://leetcode.com/problems/merge-k-sorted-lists/solution/
Brute force

Traverse all the linked lists and collect the values of the nodes into an array.
Sort and iterate over this array to get the proper value of nodes.
Create a new sorted linked list and extend it with the new nodes.
//Time complexity : O(N\log N)O(NlogN)
//creating a new linked list n times costs O(N) space.


Optimize using priority queue o(nlogk)time
struct compare{
      bool operator()(ListNode* a, ListNode* b){
        return (b->val)<(a->val);
    }  
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare>pq;
        ListNode* dummy=new ListNode(0);
        ListNode* itr=dummy;
        ListNode *curr=NULL;

        //O(k)k is number of list, it will insert and compare the 1st node value and accordnig to that it will sort
        for(auto i:lists){ 
            if(i!=NULL)
            pq.push(i);
        }
            
            while(!pq.empty()){
                
                curr=pq.top();pq.pop();
                itr->next=curr;itr=curr;
                
                if(curr->next)
                    pq.push(curr->next);
            }
        itr->next=NULL;
        return dummy->next;
        }
    
        //time O(k)+ O(nlogk) k is number of linked list
    //space O(n) new linked list O(n) space
    