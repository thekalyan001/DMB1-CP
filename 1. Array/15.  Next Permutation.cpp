https://leetcode.com/problems/next-permutation/

/*
    1. Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, just reverse nums and done.
    2. Find the largest index l > k such that nums[k] < nums[l].
    3. Swap nums[k] and nums[l].
    4. Reverse the sub-array nums[k + 1:].
    */
    void nextPermutation(vector<int>& nums) {
        int k=0,n=nums.size();
        for(k=n-2;k>=0;k--){
            if(nums[k]<nums[k+1])
            {break;}
        }
        
        if(k<0){
            reverse(nums.begin(),nums.end());
        }
        else{
            int i;
            for(i=n-1;i>k;i--){
                if(nums[i]>nums[k])break;
            }
            
            swap(nums[i],nums[k]);
            reverse(nums.begin()+k+1, nums.end());
        }
    }