//https://leetcode.com/problems/k-closest-points-to-origin/
//this question is same as top k frequent element
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result(k);
        //maxheap storage initialization
        priority_queue<vector<int>> maxHeap;//by default will store as 0th value of vector
       
        for (auto& p : points) {
            int x = p[0], y = p[1];
            maxHeap.push({x*x + y*y, x, y}); //0th index per distance 1st->x 2nd->y coordinate
            if (maxHeap.size() > k) { //only k minimum distance store krna h
                maxHeap.pop();
            }
        }
        
        for (int i = 0; i < k; ++i) {
            vector<int> top = maxHeap.top();
            maxHeap.pop();
            result[i] = {top[1], top[2]}; //store x and y subordinate
        }
        
        return result;
    }