	vector<int> alternateSort(int arr[], int n)
	{
	   // sort(arr,arr+n);int p=0;
	   // vector<int>v(n);
	   // for(int i=0;i<=n/2;i++)
	   // {
	
	   //     v[p++]=arr[n-i-1];
	   //     p+1<n?v[p++]=arr[i]:0;
	   // }
	   // return v;
	   
	   
	   vector<int>v(n),i=0;
	   priority_queue<int>mnH;
	   priority_queue<int,vector<int>,greater<int>>mxH;
	   for(int i=0;i<n;i++)
	   {
	       mnH.push(arr[i]);
	       mxH.push(arr[i]);
	   }
	    while(mnH.top()!=mxH.top())
	    {
	        v[i++]=mxH.top();mxH.pop();
	        v[i++]=mnH.top();mnH.pop();
	    }
	    //take count variable and if <n then work
	}