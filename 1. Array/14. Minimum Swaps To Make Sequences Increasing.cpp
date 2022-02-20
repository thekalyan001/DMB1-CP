//https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/

int minSwap(vector<int>& nums1, vector<int>& nums2) {
        //taking two cases swapp on each case and dont swap
        
        int n=nums1.size();
        vector<int>x(n,0); //number of swaps needed upto i, if no swap at i
        vector<int>y(n,1); //number of swap needed upto i if swapp at i
        
        for(int i=1;i<n;i++){
            x[i]=y[i]=n;
            
            //elements are in order without a swap
            if(nums1[i-1]<nums1[i] && nums2[i-1]<nums2[i]){
                x[i]=x[i-1]; //spapp no require bcoz curr ele is greater then pre
                y[i]=y[i-1]+1; //swap no required  but you want then i swap u can do
            }
            
            ////elements are in order with a swap
            if(nums1[i-1]<nums2[i] && nums2[i-1]<nums1[i]){
                x[i]=min(x[i],y[i-1]);
                y[i]=min(y[i],x[i-1]+1);
            }
        }
        return min(x[n-1],y[n-1]);
    }