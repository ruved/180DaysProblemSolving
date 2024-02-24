class Solution {
public:
    vector<vector<int>>dist={{-1,0,1,0},{0,-1,0,1}};
    void dfs(vector<vector<int>>&board,vector<vector<bool>>&vis,int i,int j)
    {
       
    if((i<0||j<0||i==board.size()||j==board[0].size())||(board[i][j]==0)||vis[i][j]) 
        return ;
        
        vis[i][j]=true;
      
        for(int k=0;k<4;++k)
            dfs(board,vis,i+dist[0][k],j+dist[1][k]);
    }
    int numEnclaves(vector<vector<int>>& board) {
         if(board.size()==0) return 0;
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        
        for(int i=0;i<m;++i)
        {
            if(board[i][0]==1)
                dfs(board,vis,i,0);
            if(board[i][n-1]==1)
                dfs(board,vis,i,n-1);
                
        }
        for(int i=0;i<n;++i)
        {
            if(board[0][i]==1)
                dfs(board,vis,0,i);
            if(board[m-1][i]==1)
                dfs(board,vis,m-1,i);
                
        }
        int count=0;
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                if(!vis[i][j]&&board[i][j]==1)
                    count++;
        return count;
    
    }
};