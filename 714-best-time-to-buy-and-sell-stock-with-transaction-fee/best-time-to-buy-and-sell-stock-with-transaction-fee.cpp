class Solution {
public:
int help(vector<int>& prices, int &fee,int i,bool buy,vector<vector<int>>&dp){
    if(i>=prices.size()) return 0;
    if(dp[i][buy]!=-1) return dp[i][buy];
    int ans=0;
    if(buy){
        ans=-prices[i]-fee+help(prices,fee,i+1,false,dp);
    }
    else{
        ans=prices[i]+help(prices,fee,i+1,true,dp);
    }
    int ans2=help(prices,fee,i+1,buy,dp);
    return dp[i][buy]=max(ans,ans2);
}
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return help(prices,fee,0,true,dp);
    }
};