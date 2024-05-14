class Solution {
public:
int help(vector<vector<int>>& grid,int i,int j,vector<vector<bool>>&vis)
{

    if(vis[i][j]||grid[i][j]==0) return 0;

    vis[i][j]=true;
    int top=0,left=0,right=0,bottom=0;
    if(i>0&&!vis[i-1][j]&&grid[i-1][j])
        top=help(grid,i-1,j,vis);

    if(i<grid.size()-1&&!vis[i+1][j]&&grid[i+1][j])
        bottom=help(grid,i+1,j,vis);

    if(j>0&&!vis[i][j-1]&&grid[i][j-1])
        left=help(grid,i,j-1,vis);

    if(j<grid[0].size()-1&&!vis[i][j+1]&&grid[i][j+1])
        right=help(grid,i,j+1,vis);
        vis[i][j]=false;
    return grid[i][j]+max(max(top,bottom),max(left,right));
}
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans=0;
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
         for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j)
                {
        
                    ans=max(ans,help(grid,i,j,vis));
                }
         }
         return ans;
    }
};