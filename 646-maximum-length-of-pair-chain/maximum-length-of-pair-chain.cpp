class Solution {
public:
int help(vector<vector<int>>& pairs,int prev,int i,vector<vector<int>>&dp){
    if(i>=pairs.size()) return 0;
    if(dp[prev+1][i]!=-1) return dp[prev+1][i];
    int take=0;
    if(prev==-1||pairs[prev][1]<pairs[i][0])
        take=1+help(pairs,i,i+1,dp);
        
    int notake=help(pairs,prev,i+1,dp);
    return dp[prev+1][i]=max(take,notake);

}
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n=pairs.size();
        vector<vector<int>>dp(n+1,vector<int>(n,-1));
        return help(pairs,-1,0,dp);
    }
};