class Solution {
public:
    void dfs(vector<vector<int>> &adj,int i,vector<bool>&vis)
    {
        vis[i]=true;
        for (int j=0;j<adj[i].size();++j) {
          if (!vis[j]&&adj[i][j]==1)
                dfs(adj, j, vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
    int V=isConnected.size();
    vector<bool>vis(V,false);
    int count=0;
    for(int i=0;i<V;++i)
    {
        if (!vis[i]) {
            count++;
            dfs(isConnected, i, vis);
        }
    }
    return count;
    }
};