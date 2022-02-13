////https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

	// vector<int> alternateSort(int arr[], int n)
	// {
	//    sort(arr,arr+n);int p=0;
	//    vector<int>v(n);
	//    for(int i=0;i<=n/2;i++)
	//    {
	
	//        v[p++]=arr[n-i-1];
	//        p+1<n?v[p++]=arr[i]:0;
	//    }
	//    return v;
	// }


 vector<int> searchRange(vector<int>& nums, int target) {
        
       int start=0,end=nums.size()-1,mid,left,right;
       while(start<=end){
           mid=(start+end)/2;
           if(nums[mid]>=target)
               end=mid-1;
           else
               start=mid+1;
       }
        
        left=start;
        
        start=0,end=nums.size()-1;
        while(start<=end){
              mid = (start + end) / 2;
        if (nums[mid] > target)
            end = mid-1;
        else
            start = mid + 1;
        }
        right=start;
        
      return left == right ? vector<int> {-1,-1} : vector<int> {left,right-1};
    }
