class Solution {
public:
int help(string &word1, string &word2,int i,int j,vector<vector<int>>&dp){
    if(i<0) return j+1;
    if(j<0) return i+1;
    if(dp[i][j]!=-1) return dp[i][j];
   
    if(word1[i]==word2[j])
        return dp[i][j]=help(word1,word2,i-1,j-1,dp);
    else{
         int ins=help(word1,word2,i,j-1,dp);
         int del=help(word1,word2,i-1,j,dp);
         int rep=help(word1,word2,i-1,j-1,dp);
         return dp[i][j]=1+min(min(ins,del),rep);
    }

}
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return help(word1,word2,n-1,m-1,dp);
    }
};