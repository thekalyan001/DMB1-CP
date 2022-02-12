//https://leetcode.com/problems/search-in-rotated-sorted-array/ 
Naive O(n)
int search(vector<int>& nums, int target) {
    for(int i=0;i<nums.size();i++){
        if(nums[i]==target)return i;
    }
    return -1;
}

Efficient- One pass o(logn)

int search(vector<int>& nums, int target){
    int mid,left=0,end=nums.size()-1;
    while(left<=end){
        mid=(left+end)/2;
        if(nums[mid]==target)
            return mid;

            //strictly increasing
        if(nums[mid]>=nums[left]){
            if(target<=nums[mid] && target>=nums[left])
               end=mid-1;
           else 
              left=mid+1;
      } 

      else{
        if(target>=nums[mid] && target<=nums[end])
            left=mid+1;
        else
            end=mid-1; 
    }
}
return -1;
}