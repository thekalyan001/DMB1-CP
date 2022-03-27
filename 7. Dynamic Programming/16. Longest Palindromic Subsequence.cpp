1. If the first character of the string is the same as the last character, we include the first 
and last characters in the palindrome and do a recursive call for the remaining substring A[i + 1, j – 1].

2. If the last character of the string is different from the first character, we return a 

maximum of the two values we get by:
		a. removing the last character and doing a recursive call for the remaining substring A[i, j – 1].
		
		b. removing the first character and doing a recursive call for the remaining substring A[i + 1, j].



Steps:
1. L(i, i) = 1 for all indices i in the given string because every single character is a 
palindrome of length 1.

2. If the first and the last characters are not the same—that is, A[i]!= A[j], 
L(i, j) = max {L(i + 1, j), L(i, j – 1)}

3. If the first and last characters are the same—that is, A[i] == A[j], 
L(i, j) = L(i + 1, j – 1) + 2

Time Complexity: O(2N), where N denotes the length of the given input string. In the worst case,when all the characters in the given string are unique (LPS length is 1), each recursive call will end 
up in two recursive calls, thereby making the final time complexity O(2N)


-------------------------------------------------------------------------------------------------------------
recursion- TLE ❌
time- o(2^n) for every case there are two options left+1 or right-1
Space O(n), in the worst case when all the characters present in the given  string are unique recursion call


    int lps(string &s,int start, int end){
        if(start==end)return 1;
        if(start>end)return 0;
        
        if(s[start]==s[end])
            return lps(s,start+1,end-1)+2;
        else
            return max(lps(s,start+1,end),lps(s,start,end-1));
    }
    int longestPalindromeSubseq(string s) {
        return lps(s,0,s.size()-1);
    }


Memoization ☑
Time- O(n^2) Since there are N * N states in total
Space- O(n^2)2D extra table

int dp[1001][1001];
    int lps(string &s,int start, int end){
        if(start==end)return 1;
        if(start>end)return 0;
        
        if(dp[start][end]!=-1)return dp[start][end];
        if(s[start]==s[end])
            return dp[start][end]=lps(s,start+1,end-1)+2;
        else
            return dp[start][end]=max(lps(s,start+1,end),lps(s,start,end-1));
    }
    int longestPalindromeSubseq(string s) {
        memset(dp,-1,sizeof(dp));
        return lps(s,0,s.size()-1);
    }


---------------------------------Bottom-up DP-------------------
time- O(n^2)
space O(n^2)

int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n));
        for(int i=n-1;i>=0;i--){
            dp[i][i]=1;
            for(int j=i+1;j<n;j++){
                if(s[i]==s[j])
                    dp[i][j]=dp[i+1][j-1]+2;
                
                else
                    dp[i][j]=max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][n-1];

---------------------------------Bottom-up DP-------------------
