//https://www.codingninjas.com/codestudio/problems/total-negative-numbers-in-a-sorted-matrix_3161878?leftPanelTab=0
int countNegativeNumbers(vector<vector<int>> &mat)
{
    int row=mat.size();
    int clm=mat[0].size();
    int i=0, j=clm-1, ans=0;
    while(i>=0 && j>=0 && i<row && j<clm){
       if(mat[i][j]<0){
           ans+=row-i;
           j--;
       }else{
           i++;
       }
    }
    return ans;
}