class Solution {
public:
using ll = long long;
const ll INF = (1LL<<60);

    int minCost(vector<vector<int>>& grid, int k) {
         int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        int N = m * n;

        // flatten helpers
        auto idx = [&](int r, int c){ return r * n + c; };
        auto cellR = [&](int id){ return id / n; };
        auto cellC = [&](int id){ return id % n; };

        // build value list and groups (grouped by equal value, ascending order)
        vector<pair<int,int>> val_idx; val_idx.reserve(N);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                val_idx.emplace_back(grid[i][j], idx(i,j));
        sort(val_idx.begin(), val_idx.end(), [](auto &a, auto &b){
            if (a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        });

        // groups: each group has the same value; groups in ascending order of value
        vector<vector<int>> groups;
        vector<int> groupValues;
        for (int i = 0; i < N; ) {
            int j = i;
            int v = val_idx[i].first;
            groups.emplace_back();
            groupValues.push_back(v);
            while (j < N && val_idx[j].first == v) {
                groups.back().push_back(val_idx[j].second);
                ++j;
            }
            i = j;
        }

        // propagate function:
        // given starting distances startDist (size N), compute shortest distances
        // using only right/down moves (edges to (i+1,j) and (i,j+1) with cost = dest cell value)
        auto propagate = [&](const vector<ll>& startDist) {
            vector<ll> dist = startDist;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    int id = idx(i,j);
                    ll cur = dist[id];
                    if (i > 0) {
                        int up = idx(i-1, j);
                        cur = min(cur, dist[up] + (ll)grid[i][j]);
                    }
                    if (j > 0) {
                        int left = idx(i, j-1);
                        cur = min(cur, dist[left] + (ll)grid[i][j]);
                    }
                    dist[id] = cur;
                }
            }
            return dist;
        };

        // layer 0: no teleports. start only from (0,0) with cost 0
        vector<ll> prevDist(N, INF);
        prevDist[idx(0,0)] = 0;
        prevDist = propagate(prevDist); // now prevDist is dist with 0 teleports

        // iterate layers 1..k: allow at most L teleports
        for (int L = 1; L <= k; ++L) {
            // compute teleport landing starts: for each cell v, teleStart[v] = min_{u: grid[u] >= grid[v]} prevDist[u]
            vector<ll> teleStart(N, INF);
            ll currentBest = INF;
            // process groups in descending order of value
            for (int gi = (int)groups.size() - 1; gi >= 0; --gi) {
                ll groupMin = INF;
                for (int id : groups[gi]) groupMin = min(groupMin, prevDist[id]);
                currentBest = min(currentBest, groupMin);
                if (currentBest < INF) {
                    for (int id : groups[gi]) teleStart[id] = currentBest;
                }
            }

            // startDist: we can either not use the new teleport (prevDist) or teleport and land (teleStart)
            vector<ll> startDist(N, INF);
            for (int i = 0; i < N; ++i) startDist[i] = min(prevDist[i], teleStart[i]);

            // propagate normal moves (right/down) from these start distances
            vector<ll> curDist = propagate(startDist);

            // move to next layer
            prevDist.swap(curDist);
        }

        return prevDist[idx(m-1, n-1)];
    }
};