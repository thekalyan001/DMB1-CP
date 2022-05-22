//number of palindromic substring 
https://leetcode.com/problems/palindromic-substrings/


method 1:
O(n^3)
three loop and check is palindrome

method 2: O(n^2)
expand around center:
int countSubstrings(string s) {
        int beg, end, n = s.size(), res = 0;
        for(int i = 0; i < n; i++) {
            // odd length palindromic substrings
            beg = i, end = i;
            while(beg >= 0 && end < n && s[beg--] == s[end++]) res++;
            
            // even length palindromic substrings
            beg = i - 1, end = i;
            while(beg >= 0 && end < n && s[beg--] == s[end++]) res++;
        }
        
        return res;
    }