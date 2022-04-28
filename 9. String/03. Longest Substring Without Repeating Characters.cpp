Longest Substring Without Repeating Characters

M1- time- O(nLogn) logn for searching in set
space-O(n)

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		set<char>st;
		int i=0,maxx=0,n=s.size(),j=0;
		
		while(i<n){
			if(st.count(s[i])==0)
			{ 
				st.insert(s[i]);
				maxx=maxx>st.size()?maxx:st.size();
				i++;
			}
			else
				st.erase(s[j]),j++;
			
		}
		return maxx;
	}
};


O(n)  O(1)
#define no_of_char 256
int lengthOfLongestSubstring(string s) 
{
	int len=s.length();
	int high=0;int i=0;
	vector<int>lastindex(no_of_char,-1);
	for(int j=0;j<len;j++)
	{
		i=max(i,lastindex[s[j]]+1);
		high=max(high,j-i+1);
		lastindex[s[j]]=j;
	}
	return high;
}
