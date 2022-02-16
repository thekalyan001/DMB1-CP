//https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1#

using o(n)time O(n)space
int *findTwoElement(int *arr, int n) {
       map<int,int>mp;
       for(int i=0;i<n;i++){
           mp[arr[i]]++;
       }
       int miss,rep;
       for(int i=1;i<=n;i++){
           if(mp[arr[i-1]]>1)rep=arr[i-1];
           if(mp.find(i)==mp.end())miss=i;
       }
       //cout<<rep<<" "<<miss<<endl;
       int *ans=new int[2];
       ans[0]=rep;
       ans[1]=miss;
       return ans;
       
       
}


O(n)time o(1)space
int *findTwoElement(int *arr, int n) {
       int rep,miss;
       for(int i=0;i<n;i++){
           if(arr[abs(arr[i])-1]>0)
                arr[abs(arr[i])-1]*=-1;
           else
           rep=abs(arr[i]);
       }
       for(int i=0;i<n;i++){
           if(arr[i]>0)miss=i+1;
       }
       int *ans=new int[2];
       ans[0]=rep;
       ans[1]=miss;
       return ans;
    }