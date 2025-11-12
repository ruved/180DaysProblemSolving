class Solution {
public:
int help(vector<vector<int>>& grid, int k,int i,int j,vector<vector<vector<int>>>&dp){
    
    if(i==0&&j==0) return k>=0?grid[i][j]:-1;
    if(k<0||i<0||j<0) return -1;
    if(dp[k][i][j]!=INT_MIN) return dp[k][i][j]; 
    int t=grid[i][j]>0?1:0;
    int temp= max(help(grid,k-t,i-1,j,dp),help(grid,k-t,i,j-1,dp));
    if(temp!=-1)
     temp+=grid[i][j];
     return dp[k][i][j]=temp;
}
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>>dp(k+1,vector<vector<int>>(m,vector<int>(n,INT_MIN)));
        return help(grid,k,m-1,n-1,dp);
    }
};