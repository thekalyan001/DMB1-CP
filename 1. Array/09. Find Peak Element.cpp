https://leetcode.com/problems/find-peak-element/

int BinarySearch(vector<int>&nums,int start,int end)
    {
        int mid=(start+end)/2;
        if(nums[mid]<nums[mid+1]) //if mid value is <mid+1 so not peak goto right side to find
            return BinarySearch(nums,mid+1,end);
        
        //if mid value is < mid-1 so not peak goto right side to find
        if(nums[mid]<nums[mid-1])
            return BinarySearch(nums,start,mid-1);
        else return mid;
    }
    int findPeakElement(vector<int>& nums) {
                int n=nums.size();
        if(n==1)return 0; //only one so return 0th index
        
        //-1 index is -infinity so if 1th index is less then 0th then 0th is peak
        if(nums[0]>nums[1]) 
            return 0;
        if(nums[n-1]>nums[n-2])
            return n-1;
        
        //call binary search 
        int index=BinarySearch(nums,0,n-1);
        return index;
        
    
        // //[6,10,4,3,8,9,12]
        // int l=0,h=nums.size()-1,mid;
        // while(l<h)
        // {
        //     mid=(l+h)/2;
        //     if(nums[mid]>nums[mid+1])
        //         h=mid;
        //     else
        //         l=mid+1;
        // }
        // return l;
    }