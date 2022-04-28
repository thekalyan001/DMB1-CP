//https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1/#

time O(nlogn) space O(n)
int maxLen(vector<int>&arr, int n)
    {   
        unordered_map<int,int>mp;
        int sum=0, mx=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==0){
                mx=i+1;
            }
            else{
                if(mp.find(sum)!=mp.end()){
                    mx=max(mx, i-mp[sum]);
                }
                else{
                    mp[sum]=i;
                }
            }
            
        }
        return mx;
    }
