#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define rep(i,n) for(ll i=0;i<n;i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
static int p=0;
vector<string>v;
void call(string s,int st,int len)
{
  if(st==len)
    {v.pb(s);}

  else
  {
    for(int i=st;i<=len;i++)
    {

      swap(s[i],s[st]);

      call(s,st+1,len);
      
      swap(s[i],s[st]);
    }
  }
}

int main()
{
 
  fastio;
   string s;cin>>s; //aabac
   int f=0;
   call(s,0,s.length()-1);
   cout<<v.size()<<endl;
   sort(v.begin(), v.end());
   for(auto& i:v){cout<<i<<endl;}

    return 0;
}
