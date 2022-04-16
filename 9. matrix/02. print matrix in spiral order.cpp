https://leetcode.com/problems/spiral-matrix/


vector<int> spiralOrder(vector<vector<int>>& matrix) {
         vector<int>res;
        
        if(matrix.size()==0)
            return res;
        int rowBegin=0,rowEnd=matrix.size()-1,clmBegin=0,clmEnd=matrix[0].size()-1;
        
    
        while(rowBegin<=rowEnd && clmBegin<=clmEnd)
        {
            //right
            for(int i=clmBegin;i<=clmEnd;i++)
                res.push_back(matrix[rowBegin][i]);
            rowBegin++;
            
            //down
            for(int i=rowBegin;i<=rowEnd;i++)
                res.push_back(matrix[i][clmEnd]);
            clmEnd--;
            
            //left 
            if (rowBegin <= rowEnd) {
            for(int i=clmEnd;i>=clmBegin;i--)
                res.push_back(matrix[rowEnd][i]);
            }
            rowEnd--;
            
            
            if(clmBegin <= clmEnd) {
            //up
            for(int i=rowEnd;i>=rowBegin;i--)
                res.push_back(matrix[i][clmBegin]);
            }
            clmBegin++;
            
        }
        return res;
    }