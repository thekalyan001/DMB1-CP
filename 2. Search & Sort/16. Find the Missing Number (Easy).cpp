M1- using external array

using int missingNumber(vector<int>& nums) {
        vector<int>v(nums.size()+1,0);
        for(int i:nums)
        {
           v[i]=1;     
        }
        for(int i=0;i<v.size();i++)
            if(v[i]==0)return i;
        
        return -1;
    }


M2- yet to discuss