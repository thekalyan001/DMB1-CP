//Problem is print all the paths of N queen
 //https://leetcode.com/problems/n-queens/

    bool isSafe(vector<string>&nQueen, int row, int clm,int n){
        int i,j;
        
        //same row diffnt clm,  /* Check this row on left side */
        for(i=clm;i>=0;i--){
            if(nQueen[row][i]=='Q')return false;
        }
        
         /* Check this row on left side */
        for(i=row,j=clm;i>=0 && j>=0;i--,j--){
            if(nQueen[i][j]=='Q') return false;
        }
        
        /* Check lower diagonal on left side */
        for(i=row,j=clm; i<n && j>=0; i++,j--){
            if(nQueen[i][j]=='Q')return false;
        }
        return true;
    }
    void solve(vector<vector<string>>&res, vector<string>&nQueen, int clm, int &n){ //nQueen is board
        if(clm==n){ //if we reached to the final solution
            res.push_back(nQueen);
            return;
        }
        
        for(int row=0;row<n;row++){ //traverse in all row
            if(isSafe(nQueen, row, clm,n)){ 
                nQueen[row][clm]='Q';
                solve(res,nQueen, clm+1, n); //check all column of the current row
                nQueen[row][clm]='.'; //back
                
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> > res; //result vector to store
        vector<string> nQueens(n, string(n, '.')); //board vector n*n with . as default, n string size 
        solve(res, nQueens, 0, n); //res, queen, clm, n
        return res;
       
    }



----------------------------------------. N-Queens II count total ways-----------
https://leetcode.com/problems/n-queens-ii/

similar to uper wala swaal bas isme count krna h and uper me insert krna tha

//Problem is print all the paths of N queen
    bool isSafe(vector<string>&nQueen, int row, int clm,int n){
        int i,j;
        
        //same row diffnt clm,  /* Check this row on left side */
        for(i=clm;i>=0;i--){
            if(nQueen[row][i]=='Q')return false;
        }
        
         /* Check this row on left side */
        for(i=row,j=clm;i>=0 && j>=0;i--,j--){
            if(nQueen[i][j]=='Q') return false;
        }
        
        /* Check lower diagonal on left side */
        for(i=row,j=clm; i<n && j>=0; i++,j--){
            if(nQueen[i][j]=='Q')return false;
        }
        return true;
    }
    void solve(vector<vector<string>>&res, vector<string>&nQueen, int clm, int &n){ //nQueen is board
        if(clm==n){ //if we reached to the final solution
            res.push_back(nQueen);
            return;
        }
        
        for(int row=0;row<n;row++){ //traverse in all row
            if(isSafe(nQueen, row, clm,n)){ 
                nQueen[row][clm]='Q';
                solve(res,nQueen, clm+1, n); //check all column of the current row
                nQueen[row][clm]='.'; //back
                
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> > res; //result vector to store
        vector<string> nQueens(n, string(n, '.')); //board vector n*n with . as default, n string size 
        solve(res, nQueens, 0, n); //res, queen, clm, n
        return res;
       
    }