 https://practice.geeksforgeeks.org/problems/cf0cd86c66d07222499f84ec22dbcf6cae30e848/1#

Input:
N = 4
ar[] = {geeksforgeeks, geeks, geek, geezer}

Output:
gee



Explanation: 
Longest common prefix in all the given string is gee. 

string LCP(string ar[], int n)
    {
        sort(ar, ar+n);
        long long len=ar[0].size();
        string ans;
        for(long long i=0;i<len;i++){
            if(ar[0][i]==ar[n-1][i])
            ans+=ar[0][i];
            else
            break;
        }
        return ans.size()>=1?ans:"-1";
    }