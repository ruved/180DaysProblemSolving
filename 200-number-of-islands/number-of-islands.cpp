class Solution {
public:
    
    bool isSafe(vector<vector<char>>& grid,int row,int col,vector<vector<bool> >&visited)
    {
    return row>=0&&row<visited.size()&&col>=0&&col<visited[0].size()&&grid[row][col]=='1'&&!visited[row][col];
    }
  void  DFScount(vector<vector<char>>& grid,int row,int col,vector<vector<bool> >&visited)
  {
      int rowbar[]={-1,0,1,0};
      int colbar[]={0,-1,0,1};
      visited[row][col]=true;
      for(int k=0;k<4;++k)
          if(isSafe(grid,row+rowbar[k],col+colbar[k],visited))
              DFScount(grid,row+rowbar[k],col+colbar[k],visited);
      
  }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0)
            return 0;
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<bool> >visited(n,vector<bool>(m,0));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            if(grid[i][j]=='1'&&!visited[i][j]){
                DFScount(grid,i,j,visited);
                count++;
            }
                return count;
    }
};