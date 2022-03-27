https://leetcode.com/problems/add-binary/

string addBinary(string a, string b) {
        int carry=0;
        int i=a.size()-1, j=b.size()-1;
        
            
        string res;
        while(i>=0 || j>=0|| carry){ 
            
            if(i>=0){
                carry+=(a[i]-'0'); //char to int
                i--;
            }
            
             if(j>=0){
                carry+=(b[j]-'0');
                j--;
            }
            
                res+=(carry%2 +'0'); //num to char
                carry=carry/2;
        }
        reverse(res.begin(),res.end());
        return res;
    }