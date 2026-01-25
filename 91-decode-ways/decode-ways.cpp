class Solution {
public:
int help(string &s,int i,vector<int>&dp){
    if(i>=s.length()) return 1;
    if(s[i]=='0') return 0;
    if(dp[i]!=-1) return dp[i];
    int count=0;
    if(((i+1)<s.length())&&(s[i]=='1'||(s[i]=='2'&&s[i+1]<='6')))
      count+=help(s,i+2,dp);
    count+=help(s,i+1,dp);
   return dp[i]=count;
   }
    int numDecodings(string s) {
        vector<int>dp(s.length(),-1);
        return help(s,0,dp);
    }
};