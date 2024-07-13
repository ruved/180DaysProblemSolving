class Solution {
public:
int help(vector<vector<int>>& pairs,int i,vector<int>&dp){
    if(i<0) return 0;

    if(dp[i]!=-1) return dp[i];
    int ans=0;

    for(int j=0;j<i;++j){
        if(pairs[j][1]<pairs[i][0])
            ans=max(ans,1+help(pairs,j,dp));
    }
    return dp[i]=ans;
}
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        vector<int>dp(n,-1);
        sort(pairs.begin(),pairs.end());
        return help(pairs,n-1,dp)+1;
    }
};