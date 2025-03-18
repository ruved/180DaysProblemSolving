class Solution {
public:
int help(string &word1, string &word2,int i,int j,vector<vector<int>>&dp){
    if(i<0||j<0) return 0;
    
    if(dp[i][j]!=-1) return dp[i][j];
   
    if(word1[i]==word2[j])
        return dp[i][j]=1+help(word1,word2,i-1,j-1,dp);
    else{
         int t1=help(word1,word2,i,j-1,dp);
         int t2=help(word1,word2,i-1,j,dp);
         return dp[i][j]=max(t1,t2);
    }

}
    int longestCommonSubsequence(string text1, string text2) {
         int n=text1.length();
        int m=text2.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return help(text1,text2,n-1,m-1,dp);
    }
};