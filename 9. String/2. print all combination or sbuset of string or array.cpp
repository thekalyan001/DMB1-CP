 //https://practice.geeksforgeeks.org/problems/subsets-1613027340/1#

 vector<vector<int>>ans;
    void findSet(vector<int>& arr, vector<int>&v, int index){
        ans.push_back(v);
        for(int i=index;i<arr.size();i++){
            v.push_back(arr[i]);
            findSet(arr,v, i+1);
            v.pop_back();
        }
        
    }
    vector<vector<int> > subsets(vector<int>& arr)
    {
        ans.clear();
        vector<int>v;
        findSet(arr,v,0);
        sort(ans.begin(),ans.end());
        return ans;
    }


//O(2^(number of element)) for every element there are two options are there