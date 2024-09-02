class Solution {
public:
bool help(string &p, string &s,int i,int j,vector<vector<int>>&dp){
    if(i==p.length())   
        return j==s.length();

    if(j==s.length())
       return dp[i][j]=(p[i]=='*'&&help(p,s,i+1,j,dp));

    if(i==p.length()||j==s.length()) return false;
    // cout<<i<<" "<<j<<"+";
    if(dp[i][j]!=-1) return dp[i][j];

    if((p[i]==s[j])||(p[i]=='?'))
        return dp[i][j]=help(p,s,i+1,j+1,dp);

    else if(p[i]=='*'){
        return dp[i][j]=help(p,s,i+1,j,dp)||help(p,s,i,j+1,dp);
    }else
        return dp[i][j]=false;
        

}
    bool isMatch(string s, string p) {
        int m=p.length();
        int n=s.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return help(p,s,0,0,dp);
    }
};