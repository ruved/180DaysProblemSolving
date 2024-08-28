class Solution {
public:

int help(string &s,int i,int j,vector<vector<int>>&dp){
    if(i>j) return 0;
    if(i==j) return 1;
    if(dp[i][j]!=-1) return dp[i][j];

    int take=0;
    if(s[i]==s[j])
        take=2+help(s,i+1,j-1,dp);
    
    int notake=max(help(s,i+1,j,dp),help(s,i,j-1,dp));
    return dp[i][j]=max(take,notake);
}
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return help(s,0,s.length()-1,dp);
    }
};