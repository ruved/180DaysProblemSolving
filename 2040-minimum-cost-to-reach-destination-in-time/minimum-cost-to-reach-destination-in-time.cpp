class Solution {
public:
    struct State {
    int cost;     // total passing fee paid so far
    int node;     // current city
    int time;     // time spent so far
    bool operator>(const State& other) const {
        return cost > other.cost;
    }
};

int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
    int n = passingFees.size();

    // Build adjacency list: u -> {v, travelTime}
    vector<vector<pair<int,int>>> graph(n);
    for (auto &e : edges) {
        int u = e[0], v = e[1], t = e[2];
        graph[u].push_back({v, t});
        graph[v].push_back({u, t});
    }

    // dp[node][time] = minimum cost to reach node at exactly 'time'
    const int INF = 1e9;
    vector<vector<int>> dp(n, vector<int>(maxTime+1, INF));

    // Min-heap by cost
    priority_queue<State, vector<State>, greater<State>> pq;
    dp[0][0] = passingFees[0];
    pq.push({passingFees[0], 0, 0});

    while (!pq.empty()) {
        auto [cost, u, t] = pq.top();
        pq.pop();

        // If we reached destination
        if (u == n-1) return cost;

        // If we already have better cost, skip
        if (cost > dp[u][t]) continue;

        // Relax edges
        for (auto &[v, w] : graph[u]) {
            int newTime = t + w;
            if (newTime <= maxTime) {
                int newCost = cost + passingFees[v];
                if (newCost < dp[v][newTime]) {
                    dp[v][newTime] = newCost;
                    pq.push({newCost, v, newTime});
                }
            }
        }
    }
    return -1; 
}
};