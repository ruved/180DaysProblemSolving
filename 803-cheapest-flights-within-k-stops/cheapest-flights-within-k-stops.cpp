class Solution {
public:
struct State {
    int cost;   // total price so far
    int city;   // current city
    int stops;  // number of stops used so far
    bool operator>(const State& other) const {
        return cost > other.cost;
    }
};

int findCheapestPrice(int n, vector<vector<int>>& flights,
                              int src, int dst, int k) {
    // Build adjacency list: city -> {neighbor, price}
    vector<vector<pair<int,int>>> graph(n);
    for (auto &f : flights) {
        int u = f[0], v = f[1], w = f[2];
        graph[u].push_back({v, w});
    }

    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({0, src, 0}); // cost, city, stops

    vector<int> minStops(n, INT_MAX); // track minimal stops used to reach city

    while (!pq.empty()) {
        auto [cost, u, stops] = pq.top(); pq.pop();

        if (u == dst) return cost;

        if (stops > k || stops >= minStops[u]) continue;
        minStops[u] = stops;

        for (auto &[v, w] : graph[u]) {
            pq.push({cost + w, v, stops + 1});
        }
    }

    return -1;
}
   
};