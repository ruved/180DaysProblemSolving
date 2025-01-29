class Solution {
public:
int help(int n,bool turn, vector<vector<int>>&dp){
    if(n==1) return !turn;
    if(dp[n][turn]!=-1) return dp[n][turn];
    bool ans=false;
    for(int x=1;x<=n-1;++x){
            if(n%x==0 && turn==help(n-x,!turn,dp)) 
                return dp[n][turn]=turn;
    }
    return dp[n][turn]=!turn;
}
    bool divisorGame(int n) {
        bool turn=true;
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
       return  help(n,turn,dp);
    }
};