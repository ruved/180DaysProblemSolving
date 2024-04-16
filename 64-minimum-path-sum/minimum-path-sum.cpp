class Solution {
public:
int help(vector<vector<int>>& grid,int i,int j,vector<vector<int>>&dp)
{
    if(i<0||j<0) return INT_MAX;
    if(i==0&&j==0) return grid[i][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int minval=min(help(grid,i-1,j,dp),help(grid,i,j-1,dp));
    return dp[i][j]=minval==INT_MAX?minval:grid[i][j]+minval;
}
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size()==0) return 0;
        int row=grid.size()-1;
        int col=grid[0].size()-1;
        vector<vector<int>>dp(row+1,vector<int>(col+1,-1));
       return help(grid,row,col,dp);
    }
};
//grid[i][j]+min(fun([i][j]->down),fun([i][j]->right)