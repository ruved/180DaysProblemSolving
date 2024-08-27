class Solution {
public:
int mod=1e9+7;
vector<vector<int>>numpadKnight={{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}};

int help(int n,int pos,vector<vector<int>>&dp){
    if(n<=0) return 1;
    if(dp[pos][n]!=-1) return dp[pos][n];
    long res=0;
    for(int j=0;j<numpadKnight[pos].size();++j){
        res+=help(n-1,numpadKnight[pos][j],dp);
        res=res%mod;
        }
     return dp[pos][n]=res%=mod;
}
    int knightDialer(int n) {
        long res=0;
        vector<vector<int>>dp(10,vector<int>(n+1,-1));
        for(int i=0;i<=9;++i){
            res+=help(n-1,i,dp);
            res%=mod;
        }
        return res;
    }
};