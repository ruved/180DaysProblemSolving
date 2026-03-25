class Solution {
public:
int help(vector<vector<int>>& grid,int i,int j1,int j2,vector<vector<vector<int>>>&dp){
    if(i>=grid.size()) return 0;
    if(j1<0||j1>=grid[0].size()||j2<0||j2>=grid[0].size())
    return INT_MIN;
    if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
    int ans=INT_MIN;
    
    for(int k=-1;k<=1;++k)
        for(int l=-1;l<=1;++l)
            ans=max(ans,help(grid,i+1,j1+k,j2+l,dp));
   int res=j1==j2?grid[i][j1]:grid[i][j1]+grid[i][j2];
   return dp[i][j1][j2]=res+ans;
}
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return help(grid,0,0,grid[0].size()-1,dp);
    }
};