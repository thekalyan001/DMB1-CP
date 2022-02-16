 //https://leetcode.com/problems/top-k-frequent-elements/

//basic method o(3n)+o(nlogn)=O(nlogn)  space O(2n)
    
    //use sort function with 2nd value sorted
    //sort array using second value

M1-o(3n)+o(nlogn)=O(nlogn)  space O(2n)

struct comperator{
  bool operator()(pair<int,int>a,pair<int,int>b){
          return a.second>b.second; //agar first wala greater hai to return yes
      }  
  };
  vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int>ans;
    int n=nums.size();
    unordered_map<int,int>mp;
        for(int i=0;i<n;i++)mp[nums[i]]++; //O(n)

            vector<pair<int,int>>temp;
        for(auto it:mp){ //O(n)
            temp.push_back({it.first,it.second});
        }
        
        sort(temp.begin(),temp.end(),comperator()); //o(nlogn)
        // for(auto it:temp){
        //     cout<<it.first<<" "<<it.second<<endl;;
        // }
        
        for(auto it:temp){ //O(n)
            if(k<=0)break;
            ans.push_back(it.first);k--;
        }
        return ans;
    }



 //max_heap O(n log(n-k))
    M-2  using max heap
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        int n=nums.size();
        unordered_map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        priority_queue<pair<int,int>> pq; 
        for(auto itr=mp.begin();itr!=mp.end();itr++)
        {
            pq.push(make_pair(itr->second, itr->first));
                if(pq.size()>(int)mp.size()-k)//mp size me se k element lenge bhai quki hame k chahyie
                {
                    ans.push_back(pq.top().second);pq.pop();
                }
            }
            return ans;
        }



        M2-
    //O(nlogk) using min heap

        vector<int> topKFrequent(vector<int>& nums, int k) {
            vector<int>ans;
            int n=nums.size();
            unordered_map<int,int>mp;
            for(auto it:nums)mp[it]++;

                priority_queue<int,vector<int>,greater<int>>mn_heap;

            for(auto itr:mp){
                mn_heap.push(itr.second);
                if(mn_heap.size()>k)
                    mn_heap.pop();
            }

            for(auto itr:mp){
                if(itr.second>=mn_heap.top())
                    ans.push_back(itr.first);
            }
            return ans;
        }



M4-
Using bucket sort o(n)time and O(n^2)space

        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int, int> cnt;
            for (int x : nums) cnt[x]++;

                int n = nums.size();
        vector<vector<int>> bucket(n+1, vector<int>()); //same fre wale element ko particualr clm me ghusa denge
        for (auto [num, freq] : cnt) {
            bucket[freq].push_back(num);
        }
        int bucketIdx = n;
        vector<int> ans;
        while (k > 0) {
            while (bucket[bucketIdx].size() == 0) { // Skip empty bucket!
                bucketIdx -= 1;
            }
            for (int x : bucket[bucketIdx]) {
                if (k == 0) break;
                ans.push_back(x);
                k -= 1;
            }
            bucketIdx -= 1;
        }
        return ans;
    }
