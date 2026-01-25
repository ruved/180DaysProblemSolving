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
        int n=s.length();
        // vector<int>dp(n+1,0);
        // return help(s,0,dp);
        vector<int>dp(3,0);
        dp[n%3]=1;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0')
                dp[i%3]=0;
            else{
                int  count=0;
                if(((i+1)<n)&&(s[i]=='1'||(s[i]=='2'&&s[i+1]<='6')))
                    count+=dp[(i+2)%3];
                count+=dp[(i+1)%3];
                dp[i%3]=count;
            }
        }
        return dp[0];

    }
};