class Solution {
public:

vector<vector<int>>path={{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}};
int mod=1e9+7;
int help(int n,int d,vector<vector<int>>&dp){
    if(n<=0) return 1;
    if(dp[n][d]!=-1) return dp[n][d];
    long unsigned sum=0;
    for(int j=0;j<path[d].size();++j){
        sum+=help(n-1,path[d][j],dp);
        sum%=mod;
    }

    return dp[n][d]=sum%mod;
}
    int knightDialer(int n) {
        long sum=0;
        vector<vector<int>>dp(n,vector<int>(10,-1));
        for(int i=0;i<=9;++i){
            sum+=help(n-1,i,dp);
            sum%=mod;
        }
        
        return sum%mod;
    }
};