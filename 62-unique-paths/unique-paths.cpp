class Solution {
public:
int help(int m, int n, vector<vector<int>>&dp){
    if(m==0&&n==0) return 1;
        if(m<0||n<0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        return dp[m][n]=help(m-1,n,dp)+help(m,n-1,dp);
}
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        // return help(m-1,n-1,dp);
        dp[0][0]=1;
        // for(int i=1;i<m;++i) dp[i][0]=1;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(i>0&&j>0) 
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];// help(m-1,n,dp)+help(m,n-1,dp);
                else if(i>0)
                    dp[i][j]=dp[i-1][j];
                else if(j>0)
                    dp[i][j]=dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};