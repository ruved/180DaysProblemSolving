class Solution {
public:
void help(vector<vector<int>>& isConnected,int i,vector<bool>&vis){
    
    vis[i]=true;
    for(int j=0;j<isConnected.size();++j){
        if(!vis[j]&&isConnected[i][j])
        help(isConnected,j,vis);
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool>vis(n,false);
        int ans=0;
        for(int i=0;i<n;++i){
            if(!vis[i]){
                help(isConnected,i,vis);
                ans++;
            }
        }
        return ans;
    }
};