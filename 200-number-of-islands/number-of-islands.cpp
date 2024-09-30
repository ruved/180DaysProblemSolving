class Solution {
public:
void help(vector<vector<char>>& grid,int i,int j,vector<vector<bool>>&vis){
    if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||vis[i][j]||grid[i][j]=='0') return ;
    vis[i][j]=true;
    help(grid,i-1,j,vis);
    help(grid,i+1,j,vis);
    help(grid,i,j+1,vis);
    help(grid,i,j-1,vis);
}
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        int ans=0;
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                if(!vis[i][j]&&grid[i][j]=='1'){
                    help(grid,i,j,vis);
                    ans++;
                }
        return ans;
    }
};
  