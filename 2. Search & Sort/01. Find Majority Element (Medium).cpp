https://leetcode.com/problems/majority-element/


M1- using hashing and count the occourence and return the number 

M2-using count veriable if occourence is >n/2 then oviously it will cancel the other number count 
    int majorityElement(vector<int>& arr) {
        int n=arr.size();
        int count=1,cur=arr[0]; //single element always counted as 1
        for(int i=1;i<n;i++)
        {
            if(count==0)
                cur=arr[i];
            
            if(cur==arr[i])
                count++;
            else
                count--;
        }
        
        if(count>0)return cur;
        return -1;
    }
