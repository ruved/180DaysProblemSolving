class Solution {
public:
int help(vector<vector<int>>& grid,int i,int j1,int j2,vector<vector<vector<int>>>&dp){

if(i>=grid.size()||j1<0||j1>=grid[0].size()||j2<0||j2>=grid[0].size()) return 0;

    if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
    vector<int>ans;
    
    for(int k=-1;k<=1;++k)
        for(int l=-1;l<=1;++l)
            ans.push_back(help(grid,i+1,j1+k,j2+l,dp));
    
    int mx= *max_element(ans.begin(),ans.end());
    
   int sum=0;
    if(j1!=j2)
        sum=grid[i][j1]+grid[i][j2];
    else
    sum= grid[i][j1];
    return dp[i][j1][j2]=sum+mx;

}
    int cherryPickup(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<vector<int>>>dp(row,vector<vector<int>>(col,vector<int>(col,-1)));
        return help(grid,0,0,col-1,dp);
    }
};