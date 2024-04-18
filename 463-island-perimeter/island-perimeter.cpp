class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
       int ans=0;
       for(int i=0;i<grid.size();++i)
       {
        for(int j=0;j<grid[i].size();++j)
        {
            if(grid[i][j]==1)
            {
                if(i==0||(i>0 &&grid[i-1][j]==0))
                    ans++;
                if(j==0||(j>0 &&grid[i][j-1]==0))
                    ans++;
                if(i==grid.size()-1||(i<grid.size() &&grid[i+1][j]==0))
                    ans++;
                if(j==grid[i].size()-1||(j<grid[i].size() &&grid[i][j+1]==0))
                    ans++;
            }
        }
       } 
       return ans;
    }
};