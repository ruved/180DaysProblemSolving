class Solution {
public:
int mod=1e9+7;
pair<int,int> help(vector<string>& board,int i,int j,vector<vector<pair<int,int>>>&dp){
    if(i==0&&j==0) return {0,1};
    if(i<0||j<0||board[i][j]=='X') return {INT_MIN,0};
    if(dp[i][j].first!=-1) return dp[i][j];
    vector<pair<int,int>>vc;
    vc.push_back(help(board,i-1,j,dp));
    vc.push_back(help(board,i,j-1,dp));
    vc.push_back(help(board,i-1,j-1,dp));
    sort(vc.begin(),vc.end());
    pair<int,long>ans({vc[2].first,vc[2].second});
    int k=1;
    while(k>=0){
        if(ans.first==vc[k].first){
            ans.second+=vc[k--].second;
            ans.second%=mod;
        }
        else
            break;
    }
    if(ans.first!=INT_MIN&&board[i][j]!='S')
        ans.first+=(board[i][j]-'0');

    return dp[i][j]=ans;
}
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int r=board.size();
        int c=board[0].size();
        vector<vector<pair<int,int>>>dp(r,vector<pair<int,int>>(c,{-1,0}));
         pair<int,int>p=help(board,r-1,c-1,dp);
         if(p.first!=INT_MIN)
            return {p.first,p.second};
         return {0,0};
    }
};