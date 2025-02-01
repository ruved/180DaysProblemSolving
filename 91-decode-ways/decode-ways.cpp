class Solution {
public:
int help(string &s,int i,vector<int>&dp){
    if(i==s.length()) return 1;
    if(dp[i]!=-1) return dp[i];

    if(s[i]=='0') return 0;
    int ans=0;
    if(i<s.length()-1){
        if((s[i]=='1')||(s[i]=='2'&&s[i+1]<='6'))
         ans+=help(s,i+2,dp);
    }
    ans+=help(s,i+1,dp);
    return dp[i]=ans;
}
    int numDecodings(string s) {
        int n=s.length();
        vector<int>dp(n,-1);
        return help(s,0,dp);
    }
};