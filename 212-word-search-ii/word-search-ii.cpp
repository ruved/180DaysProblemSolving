class Solution {
public:
    int m,n,w;
    int dp[15][15][12];
bool search(int r, int c, int k, vector<vector<char>>& arr,string word ){
    if(k>=w) return 1;
    if(r<0 || r>=m || c<0 || c>=n || 
        arr[r][c] != word[k]) return 0;
    if(dp[r][c][k] != -1) return dp[r][c][k];

    char ch = arr[r][c];
    arr[r][c] = '#';

    bool left = search(r,c-1,k+1,arr,word);
    bool right = search(r,c+1,k+1,arr,word);
    bool up = search(r-1,c,k+1,arr,word);
    bool down = search(r+1,c,k+1,arr,word);

    arr[r][c] = ch;    
    return dp[r][c][k] = left || right || up || down;
 }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
       m = board.size();
       n = board[0].size();

       vector<string>ans;

        for(auto &word : words){
            int flag = 0;
            reverse(word.begin(),word.end());
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    w = word.length();
                    for(int l=0;l<m+1;l++){
                        for(int x=0;x<=n;x++){
                            for(int y=0;y<=w;y++)
                                dp[l][x][y] = -1;
                        }
                    }
                    if(search(i,j,0,board,word)){
                        flag=1;
                        break;
                    }
                }
                if(flag){
                    break;   
                }   
            }
            if(flag){
                reverse(word.begin(),word.end());
                ans.push_back(word);
            }
        }
        return ans;
    }
};