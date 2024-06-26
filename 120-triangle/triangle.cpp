class Solution {
public:
int help(vector<vector<int>>& triangle,int row,int col,vector<vector<int>>&dp){
    if(row==triangle.size()) return 0;
    if(dp[row][col]!=-1) return dp[row][col];
  return   dp[row][col]=triangle[row][col]+min(help(triangle,row+1,col,dp),help(triangle,row+1,col+1,dp));
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int row=triangle.size();
        vector<vector<int>>dp(row,vector<int>(row,-1));
      return  help(triangle,0,0,dp);
    }
};

// 2
// 3 4
// 6 5 7
// 4 1 8 3