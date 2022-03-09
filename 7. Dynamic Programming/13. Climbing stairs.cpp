 https://leetcode.com/problems/climbing-stairs/
 You are climbing a staircase. It takes n steps to reach the top.

 Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

---------------------------

 M1- using recursion TLE o(2^n)evey calls there are two ways
 space- depth of the recursion tree will be N. Therefore, the space complexity will be O(N)

 int ways(int n){
    if(n<=2)return n;
    return ways(n-1)+ways(n-2);
}
int climbStairs(int n) {
    return ways(n);
}

------------------------------------

M2- memoization-

time-O(n) space O(n)+O(n) for dp & for recursive calls

int dp[46];
int ways(int n){
    if(n<=2)return n;
    if(dp[n]!=-1)return dp[n];
    return dp[n]=ways(n-1)+ways(n-2);
}
int climbStairs(int n) {
    memset(dp,-1,sizeof(dp));
    return ways(n);
}



-----------------------------------------
//without recursion call  
time O(n) , space O(n)
int climbStairs(int n) {
        int dp[n+1];
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
}

-----------------------------------------

BEST-----
O(1)space  O(n)time

int climbStairs(int n) {
    if(n<=2)return n;
        int twoback=1;
        int oneBack=2;
        int curr=0;
        for(int i=3;i<=n;i++)
        {
           curr=oneBack+twoback;
           twoback=oneBack;
           oneBack=curr;
        }
        return curr;
}
