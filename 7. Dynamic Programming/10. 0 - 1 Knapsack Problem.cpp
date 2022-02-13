//https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1#

M1-using recursion  TLE
int fun(int W, int wt[], int val[], int n){
    if(n==0 || W==0)
        return 0;

        if(wt[n-1]>W) //if cant take this wt then dont include
            return fun(W,wt,val,n-1);
        
        else
            return max(fun(W,wt,val,n-1), val[n-1]+fun(W-wt[n-1],wt,val,n-1));
        
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       return fun(W,wt,val,n);
   }


   Using DP- Memoization

   int dp[1001][1001];
    //Function to return max value that can be put in knapsack of capacity W.
   int fun(int W, int wt[], int val[], int n){
    if(n==0 || W==0)
        return 0;
    if(dp[W][n]!=-1)
        return dp[W][n];

        if(wt[n-1]>W) //if cant take this wt then dont include
            return fun(W,wt,val,n-1);
        
        else
            return dp[W][n]=max(fun(W,wt,val,n-1), val[n-1]+fun(W-wt[n-1],wt,val,n-1));
        
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       memset(dp,-1,sizeof(dp));
       return fun(W,wt,val,n);
   }

   using Top-Down

   int fun(int W, int wt[], int val[], int n){
    int dp[W+1][n+1];
    for(int i=0;i<=W;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0)
                dp[i][j]=0;

            else if(wt[j-1]>W)
                dp[i][j]=dp[i-1][j];

            else 
                dp[i][j]=max(val[j-1]+dp[j-1][j-wt[j-1]], dp[i-1][j-1]);
        }
    }
   }
   int knapSack(int W, int wt[], int val[], int n) 
   { 
       memset(dp,-1,sizeof(dp));
       return fun(W,wt,val,n);
   }