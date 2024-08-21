class Solution {
public:
int help(vector<int>& piles,int st, int en,vector<vector<int>>&dp){
    if(st>en) return 0;
    if(dp[st][en]!=-1) return dp[st][en];
    int opt1=piles[st]-help(piles,st+1,en,dp);
    int opt2=piles[en]-help(piles,st,en-1,dp);
    int ans=max(opt1,opt2);
    return dp[st][en]=ans;

}
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int dif=help(piles,0,piles.size()-1,dp);
        
        return dif>0;
    }
};
