https://leetcode.com/problems/coin-change/discuss/1371738/C%2B%2B-Recursion-greater-DP-Memoization-greater-DP-Tabulation

https://leetcode.com/problems/coin-change
Recursion-  TLE

   int change(vector<int>& coin,int n,int sum){
        if(n==0 || sum==0)
            return sum==0?0:INT_MAX-1;
 
       //don't include it
       if(coin[n-1]>sum)
           return 0+change(coin,n-1,sum);
       
       return min(0+change(coin,n-1,sum),1+change(coin,n,sum-coin[n-1]));
       
   }
    int coinChange(vector<int>& coin, int sum) {
        int minCoin=change(coin,coin.size(),sum);
        return (minCoin==INT_MAX-1)?-1:minCoin;
    }

 Memoization- rec+table (top down)

 int dp[10000+1][12+1];  //new line
   int change(vector<int>& coin,int n,int sum){
        if(n==0 || sum==0)
            return sum==0?0:INT_MAX-1;
       
       if(dp[sum][n]!=-1)return dp[sum][n]; //new line
       //don't include it
       if(coin[n-1]>sum)
           return dp[sum][n]=0+change(coin,n-1,sum);
       
       return dp[sum][n]=min(0+change(coin,n-1,sum),1+change(coin,n,sum-coin[n-1]));
       
   }
    int coinChange(vector<int>& coin, int sum) {
        memset(dp,-1,sizeof(dp));
        int minCoin=change(coin,coin.size(),sum);
        return (minCoin==INT_MAX-1)?-1:minCoin;
    }


 Top Down- Tabulation

  int dp[10000+1][12+1];
   int change(vector<int>& coin,int n,int sum){
        for(int i=0;i<=sum;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || j==0) 
                    dp[i][j]=(i==0?0:INT_MAX-1);
                
                else if(coin[j-1]>i)
                    dp[i][j]=dp[i-0][j-1];
                else
                    dp[i][j]=min(dp[i][j-1], 1+dp[i-coin[j-1]][j]);
                
            }
        }
       return dp[sum][n];
   }
    
    int coinChange(vector<int>& coin, int sum) {
        memset(dp,-1,sizeof(dp));
        int minCoin=change(coin,coin.size(),sum);
        return (minCoin==INT_MAX-1)?-1:minCoin;
    }