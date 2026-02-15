class Solution {
public:
int MOD=1e9+7;
int help(int left,int right,vector<vector<int>>&dp){
    if(left==0&&right==0) return 1;
    if(dp[left][right]!=-1) return dp[left][right];
    long long ans = 0;

    // pickup
    if(left > 0)
        ans = (ans + 1LL*left * help(left-1, right, dp)) % MOD;

    // delivery
    if(right > left) {
        int open = right - left;
        ans = (ans + 1LL*open * help(left, right-1, dp)) % MOD;
    }

    return dp[left][right] = ans%MOD;
}
    int countOrders(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return help(n,n,dp);
    }
};