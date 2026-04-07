class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0, y = 0;

        vector<vector<int>> dir = {{0,1,0,-1},{1,0,-1,0}}; // N,E,S,W
        int pos = 0;

        set<pair<int,int>> st;
        for(auto &o : obstacles)
            st.insert({o[0], o[1]});
        int ans=0;
        for(int cmd : commands){
            if(cmd == -2){
                pos = (pos + 3) % 4; // left
            }else if(cmd == -1){
                pos = (pos + 1) % 4; // right
            }else{
                while(cmd--){
                    int nx = x + dir[0][pos];
                    int ny = y + dir[1][pos];

                    if(st.count({nx, ny})) break;

                    x = nx;
                    y = ny;
                }
            }
            ans=max(ans,x*x + y*y);
        }

        return ans;
    }
};