class Solution {
public:
int dp[51][51][51][51]; // 4D - dp
    int cp(int r1, int c1, int r2, int c2, vector<vector<int>>&grid)
    {
        if(r1>=grid.size() || r2>=grid.size() || c1>=grid[0].size() || c2>=grid[0].size() || grid[r1][c1]==-1 || grid[r2][c2]==-1){
            return INT_MIN;
        }
        
        // if p1 and p2 reach the destination
        if(r1 == grid.size()-1 && c1 == grid[0].size()-1)
        {
            return grid[r1][c1];    
        }
        
        if(dp[r1][c1][r2][c2]!=0)
            return dp[r1][c1][r2][c2];
        
        int cherries = 0;
        if(r1==r2 && c1==c2){
            cherries += grid[r1][c1];
        }
        else {
            cherries += grid[r1][c1] + grid[r2][c2];
        }
        
        int f1 = cp(r1, c1+1, r2, c2+1, grid); // h, h
        int f2 = cp(r1+1, c1, r2, c2+1, grid); // v, h
        int f3 = cp(r1+1, c1, r2+1, c2, grid); // v, v
        int f4 = cp(r1, c1+1, r2+1, c2, grid); // h, v
        
        cherries += max({f1,f2,f3,f4});
        return dp[r1][c1][r2][c2] = cherries;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        memset(dp,0,sizeof(dp));
        int ans = cp(0,0,0,0,grid);
        return (ans < 0) ? 0 : ans;
    }
};