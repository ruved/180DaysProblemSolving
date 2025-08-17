class Solution {
public:
    typedef pair<int,int> p;
    int minCost(int n, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[n];
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,2*w});
        }

        priority_queue<p,vector<p>,greater<p>> pq;
        vector<int> dis(n,INT_MAX);
        pq.push({0,0});
        dis[0] = 0;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int w = it.first;
            int u = it.second;
            for(auto [v,d] : adj[u]){
                if(w+d < dis[v]){
                    dis[v] = w+d;
                    pq.push({w+d,v});
                }
            }
        }

        return dis[n-1] == INT_MAX ? -1 : dis[n-1];
    }
};