int sum=0,count=0,mx=INT_MIN,n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            mx=max(sum,mx);
            if(sum<0)sum=0; 
        }
        return mx;