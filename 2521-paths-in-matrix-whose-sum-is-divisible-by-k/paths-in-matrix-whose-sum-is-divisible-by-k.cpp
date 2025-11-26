class Solution {
public:
int mod=1e9+7;
int help(vector<vector<int>>& grid, int &k,int i,int j,int sum,vector<vector<vector<int>>>&dp){
    if(i==0&&j==0) return (grid[i][j]+sum)%k==0;
    if(i<0||j<0) return 0;
    if(dp[i][j][sum]!=-1) return dp[i][j][sum];
    int left=help(grid,k,i-1,j,(sum+grid[i][j])%k,dp);
    int up=help(grid,k,i,j-1,(sum+grid[i][j])%k,dp);
    return dp[i][j][sum]=(left+up)%mod;
}
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(k+1,-1)));
        return help(grid,k,m-1,n-1,0,dp);
    }
};