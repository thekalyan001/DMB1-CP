https://leetcode.com/problems/out-of-boundary-paths/

class Solution {
public:
     //m n maxMove
    int mod=1e9+7;
    int dp[51][51][51];
    int rec(int m,int n,int move,int i,int j){
        
        //Base condi
        if(i<0 || j<0 || i>=m || j>=n) //out of bound ja skte h means found the way
            return 1;
        
        if(move==0)return 0; //cant found the sol in case way is 0
        
        if(dp[i][j][move]!=-1)
            return dp[i][j][move]%mod;
        
        
        int ans=0;
        int dx[]={-1,0,0,1};
        int dy[]={0,1,-1,0};
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            
            ans=(ans%mod+rec(m,n,move-1,x,y)%mod)%mod;
        }
        return dp[i][j][move]=ans%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                for(int k=0;k<=maxMove;k++){
                    dp[i][j][k]=-1;
                }
            }
        }
        return rec(m,n,maxMove, startRow,startColumn)%mod;
    }
};