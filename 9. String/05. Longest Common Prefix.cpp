    https://leetcode.com/problems/longest-common-prefix/

    string longestCommonPrefix(vector<string>& strs) {
     /*
        int n=strs.size();
        if(n==0)return "";
        if(n==1)return strs[0];
        
        sort(strs.begin(),strs.end());
        string a=strs[0], b=strs[n-1];
        
        string ans="";
        for(int i=0;i<a.size();i++){
            if(a[i]==b[i])ans+=a[i];
            else return ans;
        }return ans;
        
        */
//---------------------------------------------------------------        
        //optimized
        string ans=strs[0];
        int n=strs.size();
        
        for(int i=1;i<n;i++){
            int j;
            for(j=0;j<strs[i].size();j++){
                if(ans[j]!=strs[i][j])break;
            }
            
            ans=ans.substr(0,j);
            //if answr is null then dont do the computation mroe
            if(ans=="")return "";
        }
        return ans;
    }