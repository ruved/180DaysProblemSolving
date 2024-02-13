class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0;i<m;++i){
        for(int j=0;j<n;++j)
            if(grid[i][j]==2)
            {
                vis[i][j]=true;
                q.push(make_pair(i,j));
            }
        }
        int minute=-1;
        while(!q.empty())
        {
            int qsz=q.size();
              for(int i=0;i<qsz;++i)
              {
                  pair<int,int>p=q.front();
                  // cout<<p.first<<" "<<p.second<<"--";
                  q.pop();
                  if(((p.first+1)<m)&&(!vis[p.first+1][p.second])&&grid[p.first+1][p.second]==1)
                  {
                      vis[p.first+1][p.second]=true;
                      q.push({p.first+1,p.second});
                  }
                  if(((p.second+1)<n)&&(!vis[p.first][p.second+1])&&grid[p.first][p.second+1]==1)
                    {
                        vis[p.first][p.second+1]=true;
                        q.push({p.first,p.second+1});
                    }
                  if(((p.first-1)>=0)&&(!vis[p.first-1][p.second])&&grid[p.first-1][p.second]==1)
                    {
                        vis[p.first-1][p.second]=true;
                        q.push({p.first-1,p.second});
                    }
                  if(((p.second-1)>=0)&&(!vis[p.first][p.second-1])&&grid[p.first][p.second-1]==1)
                    {
                        vis[p.first][p.second-1]=true;
                        q.push({p.first,p.second-1});
                    }
              }
            minute++;
        }
        
        for(int i=0;i<m;++i){
        for(int j=0;j<n;++j)
            if(grid[i][j]==1&&!vis[i][j])
            {
               return -1;
            }
        }
        return minute==-1?0:minute;
    }
};