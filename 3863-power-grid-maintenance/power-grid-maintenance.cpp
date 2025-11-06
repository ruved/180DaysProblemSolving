class UnionFind {
    vector<int> parent, rank;
    vector<bool> online;
    unordered_map<int, set<int>> onlineStations;

public:
    UnionFind(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        online.resize(n + 1, true);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
            onlineStations[i].insert(i);
        }
    }

    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unionSet(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (rank[px] < rank[py]) swap(px, py);
        parent[py] = px;
        rank[px] += (rank[px] == rank[py]);
        if (onlineStations.count(py)) {
            onlineStations[px].insert(onlineStations[py].begin(), onlineStations[py].end());
            onlineStations.erase(py);
        }
    }

    void setOffline(int x) {
        if (!online[x]) return;
        online[x] = false;
        int px = find(x);
        onlineStations[px].erase(x);
    }

    int query(int x) {
        if (online[x]) return x;
        int px = find(x);
        if (!onlineStations.count(px) || onlineStations[px].empty())
            return -1;
        return *onlineStations[px].begin();
    }
};



class Solution {
public:
    
    
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        UnionFind uf(c);
        vector<int>res;
        for(int i=0;i<connections.size();++i){
            uf.unionSet(connections[i][0], connections[i][1]);
        }

        for(int i=0;i<queries.size();++i){
            if(queries[i][0]==1){
                res.push_back(uf.query(queries[i][1]));
            }else{
                uf.setOffline(queries[i][1]);
            }
        }
        return res;
    }
};