https://practice.geeksforgeeks.org/problems/d6e88f06b273a60ae83992314ac514f71841a27d/1#

  int smallestSubstring(string s) {
      int n=s.size();
      int a=-1,b=-1,c=-1;
      int res=INT_MAX;
      if(n>=3)
      for(int i=0;i<n;i++){
          if(s[i]=='0')a=i; 
          if(s[i]=='1')b=i;
          if(s[i]=='2')c=i;
          
          if(a!=-1 && b!=-1 && c!=-1){
              res=min(res, (max(a,max(b,c))-min(a,min(b,c)))+1 );
          }
      }
      return res!=INT_MAX?res:-1;
    }
