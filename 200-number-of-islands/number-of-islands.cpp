class Solution {
public:
bool checkboundry(vector<vector<char>>& grid,int i,int j){
    if(i<0||j<0) return true;
    if((i>=grid.size())||(j>=grid[0].size())) return true;
    return false;
}
void help(vector<vector<char>>& grid,int i,int j,vector<vector<bool>>& vis){
    if(checkboundry(grid,i,j)) return;
    if((vis[i][j])||(grid[i][j]=='0')) return ;
    vis[i][j]=true;
    help(grid,i-1,j,vis);
    help(grid,i+1,j,vis);
    help(grid,i,j-1,vis);
    help(grid,i,j+1,vis);
}
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(!vis[i][j]&&(grid[i][j]=='1')){
                    help(grid,i,j,vis);
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
};