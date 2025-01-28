class Solution {
public:
int help(vector<vector<int>>& grid,int i,int j,vector<vector<bool>>& vis){
    if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||vis[i][j]||grid[i][j]==0) 
        return 0;
        
    vis[i][j]=true;
    return grid[i][j]+help(grid,i-1,j,vis)+help(grid,i+1,j,vis)
        +help(grid,i,j-1,vis)+help(grid,i,j+1,vis);

}
    int findMaxFish(vector<vector<int>>& grid) {
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size()));
        int ans=0;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(!vis[i][j]){
                    ans=max(ans,help(grid,i,j,vis));
                }
            }
        }
        return ans;
    }
};