class Solution {
public:
bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int i,int j,vector<vector<bool>>&vis){
    if(i<0||j<0||i>=grid2.size()||j>=grid2[0].size()) return  true;
    if(vis[i][j]||grid2[i][j]==0) return true;
    if(grid2[i][j]&&grid1[i][j]==0) return false;
    vis[i][j]=true;

    bool a=dfs(grid1,grid2,i+1,j,vis);
    bool b=dfs(grid1,grid2,i-1,j,vis);
    bool c=dfs(grid1,grid2,i,j+1,vis);
    bool d=dfs(grid1,grid2,i,j-1,vis);
    return a&&b&&c&&d;
}
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid1.size();
        int n=grid1[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        int ans=0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(!vis[i][j]&&grid2[i][j])  
                    ans+=dfs(grid1,grid2,i,j,vis);
            }
        }
        return ans;
       
    }
};