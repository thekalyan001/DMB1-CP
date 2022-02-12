https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

naive- sort and check which number is missing


m1- naive is to use two loop and check the difference
for(int i=0;i<n;i++)
{
	for(int j=i+1;j<n;j++)
	{
		if(arr[i]<arr[j]);
		mxpro=max(maxPro,arr[j]-arr[i]);
	}
}


M2- by tracking min element till current point and check the difference

int maxPro=0,minEle=INT_MAX;
for(int i=0;i<n;i++)
{
	minEle=min(minEle,arr[i]); //check if current ele is min else previous min
	maxPro=max(maxPro, arr[i]-minEle);
}
cout<<maxPro<<endl;