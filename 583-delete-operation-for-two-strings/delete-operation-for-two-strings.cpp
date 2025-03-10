class Solution {
public:
int help(string &s1, string &s2,int i,int j,vector<vector<int>>&dp){
    if(i<0||j<0){
        int sum=0;
        if(i>=0){
            sum+=i+1;
        }
        if(j>=0){
            sum+=j+1;
        }
        return sum;
    }
    if(dp[i][j]!=-1) return dp[i][j];

    if(s1[i]==s2[j])
        return dp[i][j]=help(s1,s2,i-1,j-1,dp);
    else
       return dp[i][j]=1+min(help(s1,s2,i-1,j,dp),help(s1,s2,i,j-1,dp)); 
    
}
    int minDistance(string word1, string word2) {
         int n=word1.length();
        int m=word2.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return help(word1,word2,n-1,m-1,dp);
    }
};