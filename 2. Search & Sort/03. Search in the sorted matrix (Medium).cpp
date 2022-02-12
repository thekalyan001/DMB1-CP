//https://leetcode.com/problems/search-a-2d-matrix/submissions/
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int clm=matrix[0].size();
        int i=0,j=clm-1;
        
        while(i<row && j>=0)
        {
            //got it while searching
            if(target==matrix[i][j])
                return true;
            
            //if target is lesser than the cur-go left
            else if(target<matrix[i][j])
            j--;
            
            //if curr is greater than the target -go below
            else if(target>matrix[i][j])
            i++;
        }
        //nhi  mila
        return false;
    }