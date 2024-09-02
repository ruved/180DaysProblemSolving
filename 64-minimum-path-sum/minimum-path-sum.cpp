class Solution {
public:
int help(vector<vector<int>>& grid,int i,int j,vector<vector<int>>&dp){
    if(i==0&&j==0) return grid[i][j];
    if(i<0||j<0) return INT_MAX;
    if(dp[i][j]!=-1) return dp[i][j];
    int temp=min(help(grid,i-1,j,dp),help(grid,i,j-1,dp));
    return dp[i][j]=temp!=INT_MAX?grid[i][j]+temp:temp;
}
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return help(grid,m-1,n-1,dp);
    }
};