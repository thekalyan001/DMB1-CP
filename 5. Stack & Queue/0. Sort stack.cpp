//https://practice.geeksforgeeks.org/problems/sort-a-stack/1/#

//sort stack using temporary stack
void SortedStack(stack<int>&s)
{
   stack<int>temp;
   while(!s.empty()){
       int curr=s.top();
       s.pop();
       while(!temp.empty() && temp.top()<curr)
       s.push(temp.top()),temp.pop();
       
       temp.push(curr);
   }
   while(!temp.empty()){
       s.push(temp.top()),temp.pop();
   }
}



//using recursion
void sortedInsert(stack<int>&ss, int ele)
{
    if(ss.empty() or ele>ss.top())
       {
           ss.push(ele);
           return;
       }

        int temp=ss.top();ss.pop();
        sortedInsert(ss,ele);
        ss.push(temp);
    
}
void sort() //traverse all stack element and call sortedInsert
{
    if(!s.empty())
    {
        int temp=s.top();
        s.pop();
        sort();
        sortedInsert(s,temp);
    }
}

n^2 time
O(n)space
//n calls for sortStack function & for each of the call, sortedInsert is of the order of ns

use example to dry run 

| 1 |
| 4 |
| 2 |
-----