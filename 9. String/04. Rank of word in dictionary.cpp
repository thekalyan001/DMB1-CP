https://youtu.be/KbSFlG7Y-AQ

Given a string, find the rank of the string amongst its permutations sorted lexicographically. 

Example 1:

Input:
S = "abc"
Output:
1
Explanation:
The order permutations with letters 
'a', 'c', and 'b' : 
abc
acb
bac
bca
cab
cba
Example 2:

Input:
S = "acb"
Output:
2

https://practice.geeksforgeeks.org/problems/rank-the-permutations2229/1#

  		                              P    R     I     M     E
 sort krne pr char rank               4    5     2     3     1
 no. of char rank lesser              3    3     1     1     0
      factorial                       4!    3!    2!    1!   0!   +1            (n-1!, n-2,! n-3!...) 

fact*no. of char rank lesser   		  72  +  18  + 2  +  1  + 0   +1
						rank is     =>94

  long long permutation(int n){
     long long ans=1;
     if(n==0 || n==1) return 1ll;
     else{
         for(int i=1;i<=n;i++)
           ans*=(i*1ll);
     }
     return ans;
 }
   long long findRank(string str) {
       int len=str.length();
       long long ans=0;
       for(int i=0;i<len;i++){
           int less=0;
           for(int j=i+1;j<len;j++){
               if(str[j]<str[i]) less++;
           }
           ans += less*permutation(len-1-i);
       }
       ans+=1;  //add 1 to the end bcoz last wala 0! is also a char
       return ans;
   }