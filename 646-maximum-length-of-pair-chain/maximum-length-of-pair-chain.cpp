class Solution {
public:
int help(vector<vector<int>>& pairs,int i,int prev,vector<vector<int>>&dp){
    if(i==pairs.size()) return 0;
    if(dp[i][prev+1]!=-1) return dp[i][prev+1];
    int take=0,notake;
    if(prev==-1||(pairs[prev][1])<pairs[i][0])
        take=1+help(pairs,i+1,i,dp);
    notake=help(pairs,i+1,prev,dp);
    return dp[i][prev+1]=max(take,notake);
    
}
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        vector<vector<int>>dp(pairs.size(),vector<int>(pairs.size()+1,-1));
        return help(pairs,0,-1,dp);
    }
};