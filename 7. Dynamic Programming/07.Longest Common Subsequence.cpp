//https://leetcode.com/problems/longest-common-subsequence/

Recursion TLE

    int lcs(string text1,int n,string text2, int m){
        //base case
        if(n==0 || m==0)return 0;
        
        if(text1[n-1]==text2[m-1]) //if least char same call for other size
            return 1+lcs(text1,n-1,text2,m-1);
        
        return max(lcs(text1,n-1,text2,m),lcs(text1,n,text2,m-1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        return lcs(text1,text1.size(), text2,text2.size());
    }


memoization also gives TLE
    int dp[1001][1001]; //as given constrain sp size as two veriables are there
    int lcs(string text1,int n,string text2, int m){
        if(n==0 || m==0)return 0;
        
        if(dp[n][m]!=-1) //if already calculated
            return dp[n][m];
        
        if(text1[n-1]==text2[m-1]) //if last char is same
            return dp[n][m]=1+lcs(text1,n-1,text2,m-1);
        
        //check by decreasing first str size and other second str size
        return dp[n][m]=max(lcs(text1,n-1,text2,m),lcs(text1,n,text2,m-1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return lcs(text1,text1.size(), text2,text2.size());
    }
 

 TOP_DOWN

     int lcs(string text1,int n,string text2, int m){
        int dp[n+1][m+1]; //size +1 to avoid overflow
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0) //base case if any size is 0 
                    dp[i][j]=0;
                
                else if(text1[i-1]==text2[j-1]) //last char are same
                    dp[i][j]=1+dp[i-1][j-1];
                else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
         return dp[n][m];
     }
     int longestCommonSubsequence(string text1, string text2) {
        return lcs(text1,text1.size(), text2,text2.size());
    }