class Solution {
public:
// int help(vector<vector<int>>& obstacleGrid,int i,int j,vector<vector<int>>&dp){
    
//     if(i==0&&j==0) return 1;
//     if(i<0||j<0) return 0;
//     if(dp[i][j]!=-1) return dp[i][j];
//     if(obstacleGrid[i][j]==1) return 0;
//     return dp[i][j]=help(obstacleGrid,i-1,j,dp)+help(obstacleGrid,i,j-1,dp);
// }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size()-1;
        int n=obstacleGrid[0].size()-1;
        if(obstacleGrid[0][0]==1||obstacleGrid[m][n]==1) return 0;
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        // return help(obstacleGrid,m,n,dp);
        // m*n=m+n
        for(int i=0;i<=m;i++){
                if(obstacleGrid[i][0]!=1){dp[i][0]=1;}
                else{break;}
            }
        //Similarly for first column
        for(int i=0;i<=n;i++){
                if(obstacleGrid[0][i]!=1){dp[0][i]=1;}
                  else{break;}
        }
        if(m==0||n==0){return dp[m][n];}  

        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j)
            {
                if(obstacleGrid[i][j]==1) dp[i][j]=0;
                else 
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
              //help(obstacleGrid,i-1,j,dp)+help(obstacleGrid,i,j-1,dp);
            }
        }
        return dp[m][n];
        
    }
};