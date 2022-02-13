//https://leetcode.com/problems/edit-distance/

Recursion
int minD(string word1, int len1,string word2, int len2){
        if(len1==0 || len2==0)
            return len1==0?len2:len1;
       
        if(word1[len1-1]==word2[len2-1]) //if last char matches
            return dp[len1][len2]=minD(word1,len1-1, word2, len2-1);
        
        else //1+ bcoz in case both char matches then include it
        return dp[len1][len2]=1+min(minD(word1,len1-1, word2, len2-1), min(minD(word1,len1-1,word2,len2),minD(word1,len1,word2,len2-1)));
        
    }
    int minDistance(string word1, string word2) {
        return minD(word1,word1.size(),word2,word2.size());
    }


Memoization-
int dp[502][502]; //given string size -two variable h so twoD array
    int minD(string word1, int len1,string word2, int len2){
        if(len1==0 || len2==0)
            return len1==0?len2:len1;
        if(dp[len1][len2]!=-1)
            return dp[len1][len2]; 
 
        //last char is matchig means we dont have to insert or delete or replace any word to make so dont do 1+
        if(word1[len1-1]==word2[len2-1])
            return dp[len1][len2]=minD(word1,len1-1, word2, len2-1);
        
        else
        return dp[len1][len2]=1+min(minD(word1,len1-1, word2, len2-1), min(minD(word1,len1-1,word2,len2),minD(word1,len1,word2,len2-1)));
        
        
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return minD(word1,word1.size(),word2,word2.size());
    }