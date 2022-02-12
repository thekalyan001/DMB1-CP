//https://practice.geeksforgeeks.org/problems/alternative-sorting1311/1/#
vector<int> alternateSort(int arr[], int n)
{
	sort(arr,arr+n);int p=0;
	vector<int>v(n);
	for(int i=0;i<=n/2;i++)
	{

		v[p++]=arr[n-i-1];
		p+1<n?v[p++]=arr[i]:0;
	}
	return v;


}