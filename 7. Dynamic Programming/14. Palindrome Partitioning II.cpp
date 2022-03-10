https://leetcode.com/problems/palindrome-partitioning-ii/

Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.


M1- using recursion- TLE



O(N^2) 
bool isPalin(string &s, int start, int end) 
    { 
        while(start<end) 
        { 
            if(s[start++]!=s[end--]) 
                return 0; 
        }   
        return 1; 
    }
    int minCutFrom(string s,int start, int end){
        if(start==end || isPalin(s,start,end))
            return 0; //no cut needed

        int minCut=s.size()-1;
        for(int i=start;i<=end;i++){
            if(isPalin(s,start,i)){
                minCut=min(minCut, 1+minCutFrom(s,i+1,end));
            }
        }
        return minCut;
    }
    int minCut(string s) {
        return minCutFrom(s,0,s.length()-1);
    }



using memoization-

bool isPalin(string &s, int start, int end) 
    { 
        while(start<end) 
        { 
            if(s[start++]!=s[end--]) 
                return 0; 
        }   
        return 1; 
    }
    int dp[2001][2001];
    int minCutFrom(string s,int start, int end){
        if(start==end || isPalin(s,start,end))
            return 0; //no cut needed
        
        if(dp[start][end]!=-1)return dp[start][end];
        int minCut=s.size()-1;
        for(int i=start;i<=end;i++){
            if(isPalin(s,start,i)){
                minCut=min(minCut, 1+minCutFrom(s,i+1,end));
            }
        }
        return dp[start][end]=minCut;
    }
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        return minCutFrom(s,0,s.length()-1);
    }