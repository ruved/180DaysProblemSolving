class Solution {
public:
int mod=1e9+7;
    long int help(string &s,int i,vector<int>&dp){
        if(i==s.length()) return 1;

        if(dp[i]!=-1) return dp[i];
        if(s[i]=='0') return 0;
        long long unsigned ans=0;
        if((i+1<s.length())&&(s[i]=='*'||s[i]=='1'||s[i]=='2')){
            if(s[i]=='*'||s[i]=='1')
                ans+=(s[i+1]=='*'?9*help(s,i+2,dp):help(s,i+2,dp));
            ans%=mod;
            if((s[i]=='*'||s[i]=='2')&&(s[i+1]<='6'||s[i+1]=='*'))
                ans+=(s[i+1]=='*'?6*help(s,i+2,dp):help(s,i+2,dp));
            ans%=mod;
        }
        if(s[i]=='*')
            ans+=(9*help(s,i+1,dp))%mod;
        else
            ans+=help(s,i+1,dp);
       return dp[i]=ans%mod;
    }

    int numDecodings(string s) {
        vector<int>dp(s.length(),-1);
        return help(s,0,dp)%mod;
    }
};