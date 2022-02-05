//https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

int kthSmallest(vector<vector<int>>& matrix, int k) {
    
        //O(1)agar all element in row is sorted and 1st element of next row is always greater then then 
        //last element of 1st row
//         int n=matrix.size();

//         int level=k/n, traverse=k%n;
//             if(k%n!=0)
//             {
//                 return matrix[level][traverse-1];
//             }
//         else//ye shi h
//             return matrix[level-1][n-1];
        
        
        //time O(M * N * logK), where M <= 300 is the number of rows, N <= 300 is the number of columns.
        //Space: O(K)
        priority_queue<int>pq;
        int n=matrix.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++){
                pq.push(matrix[i][j]);
                if(pq.size()>k)pq.pop();
            }
        }
        return pq.top();
    }