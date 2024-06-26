class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int row=triangle.size();
        vector<vector<int>>dp(row,vector<int>(row,0));
        for(int i=0;i<row;++i)
            dp[row-1][i]=triangle[row-1][i];

        for(int r=row-2;r>=0;--r)
            for(int col=0;col<=r;++col)
            dp[r][col]=triangle[r][col]+min(dp[r+1][col],dp[r+1][col+1]);  
        
        return dp[0][0];
    }
};