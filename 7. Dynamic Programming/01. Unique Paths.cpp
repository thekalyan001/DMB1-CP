https://leetcode.com/problems/unique-paths/

int dp[101][101]={0};
   int countPaths(int i,int j,int row,int clm)
   {
       if(dp[i][j]!=0)
           return dp[i][j];
       
        if(i<0 || j<0 || i>=row || j>=clm)
            return 0;
       
       if(i==row-1 && j==clm-1)
           return 1;
       
       int right=countPaths(i,j+1,row,clm);
       int down=countPaths(i+1,j,row,clm);
       
       return dp[i][j]=right+down;
   }
    int uniquePaths(int m, int n) {
      return countPaths(0,0,m,n);
    }


    O(m*n)space and O(m*n)time

 int uniquePaths(int m, int n) {
        vector<int> cur(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                cur[j] += cur[j - 1];
            }
        }
        return cur[n - 1];
    }