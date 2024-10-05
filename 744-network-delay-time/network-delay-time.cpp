class Solution {
public:
int getMinDis(vector<bool>spt,vector<int>dis){
    int ind=INT_MAX,val=INT_MAX;
    for(int i=0;i<dis.size();++i){
        if(!spt[i]&&val>=dis[i]){
            val=dis[i];
            ind=i;
        }
    }
    return ind;
}
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<bool>spt(n,false);
        vector<int>dis(n,INT_MAX);
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<times.size();++i)
            adj[times[i][0]-1].push_back({times[i][1]-1,times[i][2]});
        dis[k-1]=0;
       
        for(int j=0;j<n-1;++j){
            int u=getMinDis(spt,dis);
            // cout<<u<<" ";
            spt[u]=true;
            for(int i=0;i<adj[u].size();++i){
                int v=adj[u][i].first;
                int w=adj[u][i].second;
                if(!spt[v]&&dis[u]!=INT_MAX&&(dis[u]+w)<dis[v])
                    dis[v]=dis[u]+w;
            }
        }
        int t=INT_MIN;
        for(int i=0;i<n;++i){
            // cout<<dis[i]<<" ";
            t=max(t,dis[i]);
        }
        return t==INT_MAX?-1:t;
    }
};