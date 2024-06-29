class Solution {
public:
int help(vector<int>& prices,int i,vector<int>&dp){
        if(prices.size()<=i) return 0;
        if(dp[i]!=-1) return dp[i];
        
        int ans=INT_MAX;

        for(int j=i+1;j<=(2*i+2);++j)
            ans=min(ans,prices[i]+help(prices,j,dp));
        return dp[i]=ans;
}
    int minimumCoins(vector<int>& prices) {
        vector<int>dp(prices.size(),-1);
      return  help(prices,0,dp);
    }
};
