//https://leetcode.com/problems/knight-probability-in-chessboard/

double dp[26][26][101];
    double prob(int n,int move,int i,int j){
        
        if(i<0 || j<0 || i>=n || j>=n) //agar bahar ja skte h to don't count
            return 0.0;
        
        if(move==0) //move 0 per not outside box to count
            return 1.0;
        
        if(dp[i][j][move]!=-1.0) //already calculated then dont calculate
            return dp[i][j][move];
        
        double ans = 0.0;
        int dx[] = {-1,-1,1,1,-2,-2,2,2};
        int dy[] = {-2,2,2,-2,-1,1,-1,1};
        
         for(int k=0;k<8;k++){  //all 8 direction me ghora 8 chal skta h from curr pos
             int x = i + dx[k];
             int y = j + dy[k];
             
             ans = ans + prob(n,move-1,x,y)/8.0;
         }
        
        return dp[i][j][move] = ans;
        
    }
    double knightProbability(int n, int k, int row, int column) {
       
        //setting all dp value default to -1.0
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                for(int k=0;k<101;k++){
                    dp[i][j][k]=-1.0;
                }
            }
        }
     
        //box size, move, row, clm
        return prob(n,k,row,column);
    }