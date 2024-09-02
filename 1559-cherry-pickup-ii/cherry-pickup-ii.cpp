class Solution {
public:
int help(vector<vector<int>>& grid,int i,int j1,int j2,vector<vector<vector<int>>>&dp){
    
    if(i>=grid.size()) return 0;
    if(j1<0||j1>=grid[0].size()||j2<0||j2>=grid[0].size()) return INT_MIN;

    if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
    int ans=grid[i][j1];;
    if(j1!=j2)
        ans+=grid[i][j2];

    int res=0;
    for(int newcol1=j1-1;newcol1<=j1+1;++newcol1)
        for(int newcol2=j2-1;newcol2<=j2+1;++newcol2)
            res=max(res,help(grid,i+1,newcol1,newcol2,dp));

    return dp[i][j1][j2]=(res!=INT_MIN)?res+ans:res;
}
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid[0].size();
        int m=grid.size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
        return help(grid,0,0,n-1,dp);
    }
};