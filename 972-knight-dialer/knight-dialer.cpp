class Solution {
public:
vector<vector<int>>cord={{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},
{1,3},{4,2}};
long long mod=1e9+7;
int help(int n,int i,vector<vector<int>>&dp){
    if(n==1) return 1;
    
    if(dp[n][i]!=-1) return dp[n][i];
    long long int ans=0;
    for(int num:cord[i]){
        if(num!=5) {
            int temp=help(n-1,num,dp);
            ans=(ans%mod+temp%mod)%mod;
        }
    }
    return dp[n][i]=ans;
}
    int knightDialer(int n) {
        long int ans=0;
        vector<vector<int>>dp(n+1,vector<int>(10,-1));
        for(int i=0;i<=9;++i){
            int temp=help(n,i,dp);
            ans=(ans%mod+temp%mod)%mod;
        }
        return ans%mod;
    }
};
// n=3
// i=1 -> 6,8 // i=2 -> 7,9 // i=3 -> 4,8 // i=4 -> 3,9 // i=5 -> 
// i=6 -> 1,7 // i=7 -> 2,6 // i=8 -> 1,3 // i=9 -> 4,1 // i=0 -> 4,6