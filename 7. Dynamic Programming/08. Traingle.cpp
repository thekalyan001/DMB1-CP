https://leetcode.com/problems/triangle/

Recursion- time O(n^2)
int solve(int i,int j,vector<vector<int>>& triangle)
{
        if(i==triangle.size()-1)
            return triangle[i][j];
        
         int val1=solve(i+1,j,triangle); //same clm
         int val2=solve(i+1,j+1,triangle); //next clm
         int ans=min(val1,val2)+triangle[i][j]; //value add krenge previous row ka then curr check
         return ans;
}
int minimumTotal(vector<vector<int>>& triangle) {
        int sol=solve(0,0,triangle);
        return sol;
}

memoization-space O(n^2)  time O(n^2)  
int dp[202][202]; //O(n^2)space
    int solve(int i,int j,vector<vector<int>>& triangle){
        if(i==triangle.size()-1)
            return triangle[i][j];
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
         int val1=solve(i+1,j,triangle);
         int val2=solve(i+1,j+1,triangle);
         int ans=min(val1,val2)+triangle[i][j]; //value add krenge previous row ka then curr check
         return dp[i][j]=ans;   
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp,-1,sizeof(dp));
        int sol=solve(0,0,triangle);
        return sol;
    }



 O(n)space se 

 int dp[202][202]; //O(n^2)space
    int solve(int i,int j,vector<vector<int>>& triangle){
            int m = triangle.size();
        for(int i = m-2;i>=0;i--){
            //starting from 2nd last row
            for(int j=0;j<triangle[i].size();j++){
                triangle[i][j] =   triangle[i][j] + min(triangle[i+1][j],triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp,-1,sizeof(dp));
        int sol=solve(0,0,triangle);
        return sol;
    }