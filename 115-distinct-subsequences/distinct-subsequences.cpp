class Solution {
public:
int help(string &s, string &t,int si,int ti,vector<vector<int>>&dp){
    if(ti<0) return 1;
    if(ti>si||si<0) return 0;
    if(dp[si][ti]!=-1) return dp[si][ti];
    int take=0;
    if(s[si]==t[ti])
        take=help(s,t,si-1,ti-1,dp);
    int skip=help(s,t,si-1,ti,dp);
    return dp[si][ti]=take+skip;

}
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return help(s,t,n-1,m-1,dp);
    }
};