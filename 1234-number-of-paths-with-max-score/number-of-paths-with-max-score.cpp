class Solution {
public:
    int mod = 1e9+7;
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<pair<int,int>>> dp(m, vector<pair<int,int>>(n, {-1,0}));
        
        dp[m-1][n-1] = {0,1}; // princess cell
        
        // Fill last row
        for(int j=n-2;j>=0;j--){
            if(board[m-1][j] != 'X' && dp[m-1][j+1].first != -1){
                int val = (board[m-1][j]=='E' || board[m-1][j]=='S') ? 0 : board[m-1][j]-'0';
                dp[m-1][j] = {dp[m-1][j+1].first + val, dp[m-1][j+1].second};
            } 
        }
        
        // Fill last column
        for(int i=m-2;i>=0;i--){
            if(board[i][n-1] != 'X' && dp[i+1][n-1].first != -1){
                int val = (board[i][n-1]=='E' || board[i][n-1]=='S') ? 0 : board[i][n-1]-'0';
                dp[i][n-1] = {dp[i+1][n-1].first + val, dp[i+1][n-1].second};
            }
        }
        
        // Main DP
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                if(board[i][j] == 'X') continue;
                
                int bestscore = -1;
                bestscore = max(bestscore, dp[i][j+1].first);   // right
                bestscore = max(bestscore, dp[i+1][j].first);   // down
                bestscore = max(bestscore, dp[i+1][j+1].first); // diag
                
                if(bestscore == -1){ 
                    dp[i][j] = {-1,0}; // unreachable
                    continue;
                }
                
                long long ways = 0;
                if(bestscore == dp[i][j+1].first) ways += dp[i][j+1].second;
                if(bestscore == dp[i+1][j].first) ways += dp[i+1][j].second;
                if(bestscore == dp[i+1][j+1].first) ways += dp[i+1][j+1].second;
                
                int val = (board[i][j]=='E' || board[i][j]=='S') ? 0 : board[i][j]-'0';
                dp[i][j] = {bestscore + val, (int)(ways % mod)};
            }
        }
        
        if(dp[0][0].first == -1) return {0,0};
        return {dp[0][0].first, dp[0][0].second};
    }
};
