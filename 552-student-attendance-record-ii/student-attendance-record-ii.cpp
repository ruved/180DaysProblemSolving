class Solution {
public:
int mod=1e9+7;
int help(int n,bool Absent,int late,vector<vector<vector<int>>>&dp){
    if(n<0) return 0;
    if(n==0) return 1;
    if(dp[n][late][Absent]!=-1) return dp[n][late][Absent];

    long long a=0,b=0,c=0;
    if(!Absent){
        a=help(n-1,true,2,dp);
    }
    if(late>0)
        b=help(n-1,Absent,0,dp)+help(n-2,Absent,0,dp);
    c=help(n-1,Absent,2,dp);
    return dp[n][late][Absent]=(a+b+c)%mod;
}
    int checkRecord(int n) {
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(3,vector<int>(2,-1)));
        return help(n,false,2,dp)%mod;
    }
};