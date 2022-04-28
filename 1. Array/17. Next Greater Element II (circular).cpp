https://leetcode.com/problems/next-greater-element-ii/

Input: nums = [1,2,1]
Output: [2,-1,2]

m1-   time-n^2+ O(2n), space- O(2n)

vector<int> nextGreaterElements(vector<int>& nums) {
      
        int n=nums.size();
        int arr[n*2];
        for(int i=0;i<2*n;i++){
            arr[i]=nums[i%n];
        }
        for(int i=0;i<n;i++){
            int nextG=-1;
            for(int j=i+1;j<2*n;j++){
                if(arr[i]<arr[j])
                {nextG=arr[j];break;}
            }
            nums[i]=nextG;
        }
            return nums;
        
        
        }



        
        m2-
        
time O(2n)
vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        stack<int>s;
         //run two times
        for(int i=(n*2)-1;i>=0;i--){
            while(!s.empty() && nums[s.top()]<=nums[i%n]) 
                s.pop();
            
            ans[i%n]=s.empty()?-1:nums[s.top()];
            
            s.push(i%n);
            
        }
        return ans;
    }