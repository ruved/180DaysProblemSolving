class Solution {
public:
int help(string &s,int i,vector<int>&dp){
    if(i>=s.length()) return  1;
    if(s[i]=='0') return 0;
    if(dp[i]!=-1) return dp[i];
    int res=0;

    if(i+1<s.length())
        if((s[i]=='2'&&s[i+1]<='6')||(s[i]=='1')) 
            res=help(s,i+2,dp);

    res+=help(s,i+1,dp);
    return dp[i]=res;

}
    int numDecodings(string s) {
        vector<int>dp(s.length(),-1);
        return help(s,0,dp);
    }
};