class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid[0].size();
        int m=obstacleGrid.size();
        if(obstacleGrid[0][0]==1||obstacleGrid[m-1][n-1]==1) return 0;

        vector<int>dp(n,0);
        for(int i=0;i<n;++i){
            if(obstacleGrid[0][i]!=0) break;
            dp[i]=1;
        }
        bool f=true;
        for(int i=1;i<m;++i){
            if(obstacleGrid[i][0]==1&&f) {
                f=false;
            }
            dp[0]=f;
            for(int j=1;j<n;++j){
                if(obstacleGrid[i][j]==0)
                    dp[j]=dp[j]+dp[j-1];
                else
                    dp[j]=0;
            }
        }

        return dp[n-1];
    }
};