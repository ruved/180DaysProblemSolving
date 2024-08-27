class Solution {
public:
int mod=1e9+7;
int help(int n,int pos,vector<vector<int>>&dp){
    if(n<=0) return 1;
    if(dp[pos][n]!=-1) return dp[pos][n];
    long res=0;
    switch(pos){
        case 0:
            res+=help(n-1,6,dp)+help(n-1,4,dp);
        break;
        case 1:
            res+=help(n-1,6,dp)+help(n-1,8,dp);
        break;
        case 2:
            res+=help(n-1,7,dp)+help(n-1,9,dp);
        break;
        case 3:
            res+=help(n-1,4,dp)+help(n-1,8,dp);
        break;
        case 4:
            res+=help(n-1,3,dp)%mod;
            res+=help(n-1,9,dp)%mod;
            res+=help(n-1,0,dp)%mod;
        break;
        // case 5:
        //     res+=help(n-1,6)+help(n-1,8);
        break;
        case 6:
            res+=help(n-1,0,dp)%mod;
            res+=help(n-1,1,dp)%mod;
            res+=help(n-1,7,dp)%mod;
        break;
        case 7:
            res+=help(n-1,2,dp)+help(n-1,6,dp);
        break;
        case 8:
            res+=help(n-1,1,dp)+help(n-1,3,dp);
        break;
        case 9:
            res+=help(n-1,4,dp)+help(n-1,2,dp);
        break;
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