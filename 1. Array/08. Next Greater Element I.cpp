 //https://leetcode.com/problems/next-greater-element-i/

 vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_map<int,int>mp;
        stack<int>s;
        int n=nums2.size();
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && s.top()<=nums2[i]) //jab tak stack me chota h current nums2 ke val se
                s.pop();
            
            if(!s.empty()) //agar stack me h ele means bda value h current se
                mp[nums2[i]]=s.top();
            
            s.push(nums2[i]);
            
        }
        
        for(int i=0;i<nums1.size();i++){
            if(mp.count(nums1[i]))
                ans.push_back(mp[nums1[i]]);
            else
                ans.push_back(-1);
        }
        return ans;
    }