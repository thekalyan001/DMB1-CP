//https://leetcode.com/problems/minimum-path-sum/
time-O(m*n)+O(m+n) space-O(m*n)

int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();//row
        int n=grid[0].size();//clm
        vector<vector<int>>dp(m,vector<int>(n,grid[0][0]));

        for(int i=1;i<m;i++){//row  sum
            dp[i][0]=dp[i-1][0]+grid[i][0];
        }
        for(int i=1;i<n;i++){//clm  sum
            dp[0][i]=dp[0][i-1]+grid[0][i];
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }



    //method 2 your can use the same array but it will modefied
    time-O(m*n)+O(m+n) space-O(1)

    int minPathSum(vector<vector<int>>& grid) {       
        int m=grid.size(); //row
        int n=grid[0].size();//clm
        
        for(int i=1;i<m;i++){ //clm sum
            grid[i][0]+=grid[i-1][0];
        }
        
        
        for(int i=1;i<n;i++){ //row sum
            grid[0][i]+=grid[0][i-1];
        }

        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                grid[i][j]+=min(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[m-1][n-1];
    }