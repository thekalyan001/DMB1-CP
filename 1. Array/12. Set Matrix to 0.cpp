//https://leetcode.com/problems/set-matrix-zeroes/
void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int clm=matrix[0].size();
        vector<int>Row(row,0),Clm(clm,0);
        for(int i=0;i<row;i++){
            for(int j=0;j<clm;j++){
                if(matrix[i][j]==0) //row=0, clm=j
                    Row[i]=1,Clm[j]=1;
            }
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<clm;j++){
                if(Row[i]==1 or Clm[j]==1){
                    matrix[i][j]=0;
                }
            }
        }
        
    }

    time 2*O(n*m), space-O(n+m)

void setZeroes(vector<vector<int>>& matrix) {
     int clm0=1,rows=matrix.size(),clms=matrix[0].size();
            for(int i=0;i<rows;i++){
                if (matrix[i][0] == 0) clm0 = 0;
                for(int j=1;j<clms;j++){
                    if(matrix[i][j]==0){
                        matrix[i][0]=0,matrix[0][j]=0;
                    }
                }
            }
        
        for(int i=rows-1;i>=0;i--){
            for(int j=clms-1;j>=1;j--){
                if(matrix[i][0]==0 or matrix[0][j]==0)
                    matrix[i][j]=0;
            }
            if(clm0==0)
                matrix[i][0]=0;
         }
        
        }