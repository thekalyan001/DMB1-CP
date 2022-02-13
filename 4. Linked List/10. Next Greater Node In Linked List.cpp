//https://leetcode.com/problems/next-greater-node-in-linked-list/
/*
Intuition

We go right-to-left, and maintain the monotonically decreasing stack:

We remove elements from the stack until the top of the stack is larger than the current element.
We do not need those elements - the current value will be used instead for the remaining elements.
The top of the stack is now our next greater element.
We push the current element to the stack.
*/
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>res,stack;
        for(auto it=head;it!=NULL;it=it->next){
            res.push_back(it->val);
        }
        
       for(int i=res.size()-1;i>=0;i--){
           int val=res[i];
           
           while(!stack.empty() && stack.back()<=val)stack.pop_back();
           
           res[i]=stack.empty()?0:stack.back();
           stack.push_back(val);
       }
        return res;
    }