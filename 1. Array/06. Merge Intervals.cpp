//https://leetcode.com/problems/merge-intervals/

vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //if interval size is <1 then kya hi overlap krega
        if(intervals.size()<=1)
            return intervals;
        //by default sort based on first value
        sort(intervals.begin(),intervals.end());
        
        int n=intervals.size();
        vector<vector<int>>res;
        res.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=res.back()[1]){
                res.back()[1]=max(res.back()[1], intervals[i][1]);
            }else{
                res.push_back(intervals[i]);
            }
        }
       
        return res;
       }