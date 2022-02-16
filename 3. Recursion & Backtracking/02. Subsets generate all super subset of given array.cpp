 //https://leetcode.com/problems/subsets/
using recursion-

     void func(vector<vector<int>>& ans, vector<int>& nums, int i, int n, vector<int>& ds)
    {
        if(i == n)
        {
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[i]);
        func(ans, nums, i+1, n, ds);
        ds.pop_back();
        
        func(ans, nums, i+1, n, ds);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int> ds;
        int n= nums.size();
        func(ans, nums, 0, n, ds);
        return ans;
    }











 //using bitmasking time O(2^n * O(n))
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>>ans;
        int size=nums.size(); //3 for example in ques
        
        int subsetNum=(1<<size); //2^size
        for(int subMask=0;subMask<subsetNum;subMask++){ //2^n times
            vector<int>subset;
            for(int i=0;i<size;i++){ //n times
                    if((subMask & (1<<i))!=0) //check if ith bit is set 
                        subset.push_back(nums[i]);
                }
                ans.push_back(subset);
            }
            return ans;
        }

/*
Power of 2
1<<n=2^n

1<<0=(1)=2^0
1<<1=(1 0)=2^1

Bit
ith bit of x is 1 or not
x&(1<<i)=0 :ith bit of x is not 1
x&(1<<i)!=0 :ith bit of x is 1

110-6
001=1<<0
-------taking &
000

110-6
010=1<<1
-------taking &
010
1<<i = 0000..1(i-1)times..00..

Binary represention 
 [1,2,3]  2^3=8 total subset
 
0 {000}- {}
1 {001}- {3} // arr 123 me binary ka 3rd bit set hai to 3rd number lenge
2 {010}- {2}
3 {011}- {2 3} // arr 123 me binary ka 2nd & 3rd bit set hai to 2nd and 3rd number lenge 
4 {100}- {1}
5 {101}- {1 3}
6 {110}- {1 2}
7 {111}- {1 2 3}
8{1000}

*/
