class Solution {
public:
int help(vector<vector<int>>& grid,int i,int j,vector<vector<int>>&dp){
    if(i==0 && j==0) return grid[i][j];
    if(i<0||j<0) return INT_MAX;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=INT_MAX;
    ans=min(help(grid,i,j-1,dp),help(grid,i-1,j,dp));
    return dp[i][j]=(ans==INT_MAX)?ans:ans+grid[i][j];
}
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return help(grid,m-1,n-1,dp);
    }
};