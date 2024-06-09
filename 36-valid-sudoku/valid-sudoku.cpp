class Solution {
public:
// bool help(stack<pair<int,int>>st,vector<vector<bool>>gridset,vector<vector<bool>>rowset,vector<vector<bool>>colset)
// {
//     if(st.empty()) return true;
//     pair<int,int>p=st.top();
//     int r=p.first;
//     int c=p.second;
//     bool ans=false;
//     for(int i=1;i<=9;++i)
//     {
//         if(!rowset[r][i-1]&&!colset[c][i-1]&&!gridset[r*3+c][i-1]) {
//             st.pop();
//             rowset[r][i-1]=true;
//             colset[c][i-1]=true;
//             gridset[r*3+c][i]=true;
//             if(help(st,gridset,rowset,colset)) return true;
//             // st.push(p);
//             // rowset[r][i-1]=false;
//             // colset[c][i-1]=false;
//             // gridset[r*3+c][i]=false;
//         }
//     }
//     return ans;
// }
    bool isValidSudoku(vector<vector<char>>& board) {
        int row=board.size();
        int col=board[0].size();
    vector<vector<bool>>gridset(9,vector<bool>(9,false));
    vector<vector<bool>>rowset(9,vector<bool>(9,false));
    vector<vector<bool>>colset(9,vector<bool>(9,false));

        stack<pair<int,int>>st;
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(board[i][j]=='.')
                    st.push({i,j});
                else{
                    if(!rowset[i][board[i][j]-'1'])
                        rowset[i][board[i][j]-'1']=true;
                    else 
                        return false; 

                    if(!colset[j][board[i][j]-'1'])
                        colset[j][board[i][j]-'1']=true;
                    else
                        return false;

                    if(!gridset[(i/3)*3+j/3][board[i][j]-'1'])
                            gridset[(i/3)*3+j/3][board[i][j]-'1']=true;
                    else
                        return false;
                }
             }
        }
       // cout<<st.size()<<" ";
         return true;
           // return help(st,gridset,rowset,colset);
    }
};