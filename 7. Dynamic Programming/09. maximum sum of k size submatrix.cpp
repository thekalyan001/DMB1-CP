https://practice.geeksforgeeks.org/problems/257a9e27fb3e58255622c8dcb06e0919cc1c6c11/1

ek hai using 4loops 
int maxSum=0;
for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
		int sum=0;
		for(int p=i;p<i+k;p++){
			for(int q=j;q<j+k;q++){
				sum+=mat[p][q];
			}	
		}
		maxSum=max(maxSum,sum);
	}
}

//using prefix sum dp
    int Maximum_Sum(vector<vector<int>> &a,int N,int k){
       vector<vector<int>>dp(N+1,vector<int>(N+1,0));
        int ans=INT_MIN;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                dp[i][j]=a[i-1][j-1];
                dp[i][j]+=dp[i-1][j];
                dp[i][j]+=dp[i][j-1];
                dp[i][j]-=dp[i-1][j-1];
                if(i>=k&&j>=k){
                    ans=max(ans,(dp[i][j]-dp[i-k][j]-dp[i][j-k]+dp[i-k][j-k]));
                }
            }
        }
        return ans;
        
    }  


You can print the max SubMatrix
https://www.techiedelight.com/find-maximum-sum-submatrix-in-given-matrix/