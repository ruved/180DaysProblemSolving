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
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return help(s,t,n-1,m-1,dp);
        // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // for(int i=0;i<=n;++i) 
        //         dp[i][0]=1;
            

        // for(int i=1;i<=n;++i){
        //     for(int j=m;j>=1;--j){
        //         int take=0;
        //         if(s[i-1]==t[j-1])
        //             // take=dp[i-1][j-1];//help(s,t,si-1,ti-1,dp);
        //         int skip=dp[i-1][j];//help(s,t,si-1,ti,dp);
        //         dp[i][j]=take+skip;
        //     }
        // }
        // return dp[n][m];

        vector<unsigned long long> dp(m+1, 0);
            dp[0] = 1;

            for(int i = 1; i <= n; i++) {
                for(int j = m; j >= 1; j--) {
                    if(s[i-1] == t[j-1])
                        dp[j] += dp[j-1];
                }
            }

            return (int)dp[m];
    }
};