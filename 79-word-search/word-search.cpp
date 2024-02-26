class Solution {
public:
    bool help(vector<vector<char>>& board,int i,int j, string word,int k,vector<vector<bool>>&vis)
    {
        if(k==word.length()) return true;
        if(i<0||j<0||i==board.size()||j==board[0].size()) return false;
        if(vis[i][j]) return false;
        
        bool ans=false;
        if(board[i][j]==word[k])
        {
            vis[i][j]=true;
            
            ans=ans||help(board,i+1,j,word,k+1,vis);
            ans=ans||help(board,i-1,j,word,k+1,vis);
            ans=ans||help(board,i,j+1,word,k+1,vis);
            ans=ans||help(board,i,j-1,word,k+1,vis);
            vis[i][j]=false;
        }
        
        return ans;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool ans=false;
        vector<vector<bool>>vis(board.size()+1,vector<bool>(board[0].size()+1,false));
        for(int i=0;i<board.size();++i)
            for(int j=0;j<board[0].size();++j)
                if(board[i][j]==word[0]&&help(board,i,j,word,0,vis))
                    return true;    
        return false;
    }
};