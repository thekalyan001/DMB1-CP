//https://leetcode.com/problems/sort-characters-by-frequency/

string frequencySort(string s) {
        int cnt[128] = {}; //freq arr total 128 char
        for (char c : s) cnt[c] += 1; //store freq

            
        //cnt[a] > cnt[b]agar freq of a > hai freq of c
        //(cnt[a] == cnt[b] && a < b) agar freq braabar hai then chota char pehle aayega
        sort(s.begin(), s.end(), [&](char a, char b) {
            return cnt[a] > cnt[b] || (cnt[a] == cnt[b] && a < b);
        });
        return s;
    }

Time o(nlogn) sort function 
space O(logn) c++ intro sort takes this much space

Optimized-
     string frequencySort(string s) {
        unordered_map<char,int> freq;
        vector<string> bucket(s.size()+1, "");
        string res;
        
        //count frequency of each character
        for(char c:s) freq[c]++;
        //put character into frequency bucket
        for(auto& it:freq) {
            int n = it.second;
            char c = it.first;
            bucket[n].append(n, c);
        }
        //form descending sorted string
         //length of string se chlenge bcoz worst case me only 1hoga char frq to n total freq ho skti h
         //aut bda digit freq phle lena h
        for(int i=s.size(); i>0; i--) {
            if(!bucket[i].empty())
                res+=(bucket[i]);
        }
        return res;
    }
//eg dadcbdca
/*
Map
3 ddd
2 aacc
1 b
*/