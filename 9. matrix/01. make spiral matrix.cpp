https://leetcode.com/problems/spiral-matrix-ii/

vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>>ans(n, vector<int>(n,0));
	int ele=1;
	int row1=0, rown=n-1, clm1=0, clmn=n-1;
	while(row1<=rown && clm1<=clmn){

            //upper left to upper right
		for(int i=clm1;i<=clmn;i++){
			ans[row1][i]=ele++;
		}
		row1++;

            //upper right to bottom right
		for(int i=row1;i<=rown;i++){
			ans[i][clmn]=ele++;
		}
		clmn--;

		//bottom right to bottom left
		for(int i=clmn;i>=clm1;i--){
			ans[rown][i]=ele++;
		}
		rown--;

		//bottom left to top left
		for(int i=rown;i>=row1;i--){
			ans[i][clm1]=ele++;
		}
		clm1++;


		cout<<row1<<" "<<rown<<" "<<clm1<<" "<<clmn<<endl;
	}
	return ans;
}