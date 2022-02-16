//https://leetcode.com/problems/valid-parentheses/
bool ismatching(char a,char s){
    if((a=='{' && s=='}')or(a=='[' && s==']')or(a=='(' && s==')'))
        return true;
    return false;
}
string isBalanced(string s) {

    int n = s.length();

    stack<char> st;

    for (int i = 0; i < n; i++)
    {
        char c = s[i];

        if (st.empty())
        {
            st.push(c);
        }
        else if (ismatching(st.top(),c))
        {
            st.pop();
        }
        else
            st.push(c);
    }

 return st.empty()?"YES":"NO";
 
}
