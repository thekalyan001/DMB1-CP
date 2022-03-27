minimum number of characters to be inserted to convert it to palindrome

https://practice.geeksforgeeks.org/problems/form-a-palindrome2544/1#


recursion


    int lcs(string a,string b,int n, int m){
        if(n==0 || m==0)return 0;
        
        if(a[n-1]==b[m-1])
        return lcs(a,b,n-1,m-1)+1;
        
        return max(lcs(a,b,n-1,m), lcs(a,b,n,m-1));
    }
    
    //bottom up
    int findMinInsertions(string s){
        string a=s;
        reverse(a.begin(),a.end());
        int lcsLen=lcs(a,s,s.size(),s.size());
        return s.size()-lcsLen;
    }

---------------------------------------------------------------

TLE in this also->  top down

int dp[501][501];
//TLE:-top down due to recursion stack space
    int lcs(string a,string b,int n, int m){
        if(n==0 || m==0)return 0;
        
        if(a[n-1]==b[m-1])
        return dp[n][m]=lcs(a,b,n-1,m-1)+1;
        
        return dp[n][m]=max(lcs(a,b,n-1,m), lcs(a,b,n,m-1));
    }
    
    //bottom up
    int findMinInsertions(string s){
        memset(dp,-1,sizeof(dp));
        string a=s;
        reverse(a.begin(),a.end());
        int lcsLen=lcs(a,s,s.size(),s.size());
        return s.size()-lcsLen;
    }

---------------------------------------------------------------
bottom up- ACCEPTED ☑
    int lcs(string a,string b,int n){
        int dp[n+1][n+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || j==0)
                {dp[i][j]=0;continue;}
                
                else if(a[i-1]==b[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
                
                else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][n];
    }
    
    //bottom up
    int findMinInsertions(string s){
        string a=s;
        reverse(a.begin(),a.end());
        int lcsLen=lcs(a,s,s.size());
        return s.size()-lcsLen;
    }