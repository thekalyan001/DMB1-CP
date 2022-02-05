//https://leetcode.com/problems/largest-rectangle-in-histogram/

vector<int>find_rightmin(vector<int>arr){
        int n=arr.size();
        vector<int>res(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            res[i]=(st.empty())?n:st.top();
            st.push(i);
        }
        return res;
    }
    vector<int>find_leftmin(vector<int>arr){
        int n=arr.size();
        vector<int>res(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){ 
                st.pop();
            }
            res[i]=(st.empty())?-1:st.top();
            st.push(i);
        }
        return res;
    }
    int largestRectangleArea(vector<int>& arr) {
       int maxHeight=0;
       int n=arr.size();
    
        //find left min and right min 
       vector<int>rightMin=find_rightmin(arr);
       vector<int>leftMin=find_leftmin(arr);
        for(int i=0;i<n;i++){
            int width=((rightMin[i]-1)-(leftMin[i]+1))+1; //width= right-left+1
            maxHeight=max(maxHeight, width*arr[i]);
        }
        return maxHeight;
    }