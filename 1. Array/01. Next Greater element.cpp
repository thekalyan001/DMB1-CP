 //https://leetcode.com/problems/next-greater-element-i/
Brute->use two loop  
time O(n^2) space O(1)

M2 using stack and map 
 vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        vector<int>ans;
        unordered_map<int,int>mp;
        int n=nums2.size();
        for(int i=n-1;i>=0;i--){
            
            //agar next wala eleent current wale se <= hai na to simply remove kr do 
            while(!st.empty() && st.top()<=nums2[i]) 
                st.pop();
            
          if(!st.empty()) //agar stack khali nhi h current element ke liye means there is any greater element
            {
                mp[nums2[i]]=st.top();
            }
            st.push(nums2[i]);
        }
        
        //check if ther is any greater element stored in the map
        for(int num:nums1){
            if(mp.count(num))
                ans.push_back(mp[num]);
            else
                ans.push_back(-1);
        }
        return ans;
    }

Time: O(N + Q), where N <= 1000 is length of nums2 array, Q <= 1000 is length of nums1 array.
Space: O(N + Q)