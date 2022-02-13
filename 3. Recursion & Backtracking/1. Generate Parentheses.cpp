https://leetcode.com/problems/generate-parentheses/


Time Complexity : O(4n * n), for each index in string, we try both the parenthesis which is 2*2*2...2n 
times = O(22n) = O(4n) and lastly, we spend an O(n) time to check for the formed strings validity.

Space Complexity : O(4n) (A tighter bound exists)


    bool isValid(string s) {
        int balance = 0;
        for (char c: s) {
            if (c == '(') balance++;
            else balance--;
            if (balance < 0) return false;
        }
        return (balance == 0);
    }
    
    void Generate(vector<string>&ans, string &temp,int pos){
        
        if(temp.size()==pos){
            if(isValid(temp))
                ans.push_back(temp);
        }
        else{
            temp[pos]='(';
            Generate(ans,temp, pos+1);
            temp[pos]=')'; 
           
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp(2*n,'0');
        Generate(ans,temp,0);
        return ans;
    }



--another

    void sol(vector<string>&ans, string temp,int openBr, int closeBr){
        if(openBr==0 && closeBr==0){
            ans.push_back(temp);return;
        }
        
        if(closeBr>0)sol(ans,temp+")", openBr, closeBr-1);
        if( openBr>0)sol(ans,temp+"(", openBr-1, closeBr+1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        sol(ans,"",n,0);
        return ans;
    }

Time Complexity : O(4n) Here we save the time for string validation at the end and also avoid the extra recursive calls which we know are invalid anyway.
Note: There exists a tighter bound - O(4n / √n) but without deep analysis of the recursion structure, its very hard to arrive at it. So, O(4n) is good enough for quick estimations
Space Complexity : O(4n), Tighter bound - O(4n / √n)

