class Solution {
public:
int  help(vector<vector<int>>& grid,int i,int j,vector<vector<bool>>&vis){
    if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||vis[i][j]) return 0;
    if(grid[i][j]==0) return 0;
    vis[i][j]=true;
    int a=help(grid,i-1,j,vis);
    int b=help(grid,i+1,j,vis);
    int c=help(grid,i,j-1,vis);
    int d=help(grid,i,j+1,vis);
    return 1+a+b+c+d;
}
   
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        int ans=0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(!vis[i][j]&&grid[i][j]==1){
                   int temp=help(grid,i,j,vis);
                    ans=max(temp,ans);
                }    
            }
        }
        return ans;
    }
};