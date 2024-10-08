class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector< pair<int,int> > adj[n+1];
    for(auto it : edges){
        adj[it[0]].push_back({it[1],it[2] });
        adj[it[1]].push_back({it[0],it[2] });
    }
    //min heap
    priority_queue< pair<int,int> ,vector<pair<int,int>> ,greater<pair<int,int> > > pq;
    vector<int> dist(n+1,1e9+2);
    //dist node
    dist[0] =0;
    pq.push({0,0});
    while(!pq.empty()){
        auto top = pq.top();
        int dis = pq.top().first , node = pq.top().second;
        pq.pop();
        
        for(auto neigh : adj[node]){
            int adjnode = neigh.first;
            int edw = neigh.second;
            if(dist[adjnode] > dis + edw+1){
                dist[adjnode]= dis + edw+1;
                pq.push({dist[adjnode],adjnode});
            }
        }
        
    }
    int ans =0;
    for(int i=0;i<n;i++){
        if(dist[i] <= maxMoves){
            ans++;
        }
    }
    
    
    for(int i=0;i<edges.size();i++){
        int src = edges[i][0],dest = edges[i][1], between = edges[i][2];
        int fromsrc = max(0, (maxMoves- dist[src]));
        int fromdest = max(0,( maxMoves- dist[dest]));
        ans += min(between, (fromsrc+fromdest));
    }
    return ans;
    }
};