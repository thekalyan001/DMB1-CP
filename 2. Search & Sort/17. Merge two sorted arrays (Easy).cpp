 //https://leetcode.com/problems/merge-sorted-array/

 //(m+n)log(m+n) approach
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = 0 ;i<n;i++)
        {
            nums1[m+i] = nums2[i];
        }
        sort(nums1.begin(),nums1.begin()+m+n);
    }
       
    





idea is to take a pointer k at last index of nums1 and 
by comparing both array take maximum and store at the kth index and decrement it do this untill 
we finish operation for all the elemnets

    //o(m+n)
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k=(m+n)-1;
        int i=m-1,j=n-1;
        while(i>=0 && j>=0)
        {
            if(nums1[i]>=nums2[j])
                nums1[k--]=nums1[i--];
            else
                nums1[k--]=nums2[j--];
        }

        //check if nums2 elemnt is left
        while(j>=0)
        {
            nums1[k--]=nums2[j--];
        }
    }