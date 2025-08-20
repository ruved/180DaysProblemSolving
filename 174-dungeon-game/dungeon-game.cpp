class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        int n=dungeon[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        dp[m-1][n-1]=max(1,1-dungeon[m-1][n-1]);
        m--;
        n--;
        for(int i=m;i>=0;--i){
            for(int j=n;j>=0;--j){
                if(i==m&j<n)
                    dp[i][j]=max(1,dp[i][j+1]-dungeon[i][j]);
                else if(i<m&&j==n)
                    dp[i][j]=max(1,dp[i+1][j]-dungeon[i][j]);
                else if(i<m&&j<n)
                 dp[i][j]=max(1,min(dp[i+1][j],dp[i][j+1])-dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
};