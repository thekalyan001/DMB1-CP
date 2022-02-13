 //https://leetcode.com/problems/decode-ways/

Naive using recursion only (2^n)expo


    int countWays(string s,int i){

        
        if(i==s.size())
            return 1;
        
        //base condition
        if(s[i]=='0')
            return 0;
        
        //way1 [1..9]
        int way1=countWays(s,i+1);
        
        //way2 [10..26]
        int way2=0;
        if((i+1)<s.size() && (s[i]=='1' || (s[i]=='2' && s[i+1]<='6')))
         way2+=countWays(s,i+2);
        
        return way1+way2;
            
            
    }
    int numDecodings(string s) {
        return countWays(s,0);
    }
TLE aa rha tha 
-----------------


Using Dp time O(n) space O(n)recursion stack

    int dp[101]={0};
    int countWays(string s,int i){
        if(dp[i]!=0)return dp[i];
        
        if(i==s.size())
            return 1;
        
        //base condition
        if(s[i]=='0')
            return 0;
        
        //way1 [1..9]
        int way1=countWays(s,i+1);
        
        //way2 [10..26]
        int way2=0;
        if((i+1)<s.size() && (s[i]=='1' || (s[i]=='2' && s[i+1]<='6')))
         way2+=countWays(s,i+2);
        
        return dp[i]=way1+way2;
            
            
    }
    int numDecodings(string s) {
        return countWays(s,0);
    }

--------------


