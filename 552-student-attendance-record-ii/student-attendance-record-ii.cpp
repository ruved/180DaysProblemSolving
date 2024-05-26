class Solution {
public:
int mod=1e9+7;
int help(int i,int consec,bool A,vector<vector<vector<int>>>&dp){
    
    if(i==0) return 1;
    if(dp[i][consec][A]!=-1) return dp[i][consec][A];
    long long takeA=0,takeB=0,takeC=0;
    if(!A)
    takeA=help(i-1,2,true,dp);
    if(consec>0)
        takeB=help(i-1,consec-1,A,dp);
    takeC=help(i-1,2,A,dp);
    return dp[i][consec][A]=(takeA+takeB+takeC)%mod;
}
    int checkRecord(int n) {
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(3,vector<int>(2,-1)));
       return help(n,2,false,dp);
    }
};