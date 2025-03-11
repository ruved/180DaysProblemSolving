class Solution {
public:
int mod=1e9+7;
int help(string &s,int i,vector<int>&dp){
    if(i==s.length()) return 0;
    if(dp[i]!=-1) return dp[i];
    vector<int>vis(26,0);
    int ans=0;
    for(int j=i;j<s.length();++j){
        if(vis[s[j]-'a']) continue;
        vis[s[j]-'a']++;
        ans+=1+help(s,j+1,dp);
        ans=ans%mod;
    }
    return dp[i]=ans;
}
    int distinctSubseqII(string s) {
        vector<int>dp(s.length(),-1);
        return help(s,0,dp);
    }
};