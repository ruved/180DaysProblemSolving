class Solution {
public:
int help(vector<vector<int>>& grid,int i,int j,vector<vector<bool>>&vis,vector<vector<int>>&dp)
{

    if(vis[i][j]||grid[i][j]==0) return 0;

    // if(dp[i][j]!=-1) return dp[i][j];

    vis[i][j]=true;
    int top=0,left=0,right=0,bottom=0;
    if(i>0&&!vis[i-1][j])
        top=help(grid,i-1,j,vis,dp);

    if(i<grid.size()-1&&!vis[i+1][j])
        bottom=help(grid,i+1,j,vis,dp);

    if(j>0&&!vis[i][j-1])
        left=help(grid,i,j-1,vis,dp);

    if(j<grid[0].size()-1&&!vis[i][j+1])
        right=help(grid,i,j+1,vis,dp);
        vis[i][j]=false;
    return dp[i][j]=grid[i][j]+max(max(top,bottom),max(left,right));
}
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans=0;
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
         for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j)
                {
                    ans=max(ans,help(grid,i,j,vis,dp));
                }
         }
         return ans;
    }
};