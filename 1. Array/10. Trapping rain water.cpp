//https://leetcode.com/problems/trapping-rain-water/submissions/

int trap(vector<int>& height) {
        int n=height.size();
        vector<int>leftMax(n),rightMax(n);
        leftMax[0]=height[0]; //1st wala is itself max
        rightMax[n-1]=height[n-1]; //last wala is itself max
        for(int i=1;i<n;i++)
        {
            leftMax[i]=max(leftMax[i-1],height[i]); //max of prev and current
            rightMax[n-i-1]=max(rightMax[n-i],height[n-i-1]); 
        }
        int water=0;
        for(int i=1;i<n;i++)
        {
           water+=(min(leftMax[i], rightMax[i])-height[i]);
        }
        return water;
    }