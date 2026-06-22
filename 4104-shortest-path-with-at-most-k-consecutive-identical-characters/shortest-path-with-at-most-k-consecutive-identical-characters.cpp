class Solution {
public:
    int shortestPath(int n,
                     vector<vector<int>>& edges,
                     string labels,
                     int k) {

        vector<vector<pair<int,int>>> adj(n);

        for (auto &e : edges)
            adj[e[0]].push_back({e[1], e[2]});

        const long long INF = 1e18;

        vector<vector<long long>>
            dist(n, vector<long long>(k + 1, INF));

        using T = tuple<long long,int,int>;
        priority_queue<T,
                       vector<T>,
                       greater<T>> pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, c] = pq.top();
            pq.pop();

            if (d != dist[u][c])
                continue;

            for (auto [v, w] : adj[u]) {

                int nc;

                if (labels[v] == labels[u]) {
                    nc = c + 1;
                    if (nc > k)
                        continue;
                } else {
                    nc = 1;
                }

                long long nd = d + w;

                if (nd < dist[v][nc]) {
                    dist[v][nc] = nd;
                    pq.push({nd, v, nc});
                }
            }
        }

        long long ans = INF;

        for (int c = 1; c <= k; c++)
            ans = min(ans, dist[n - 1][c]);

        return ans == INF ? -1 : (int)ans;
    }
};