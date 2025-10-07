class Solution {
public:

    int swimInWater(vector<vector<int>>& grid) {
      int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<>
        > pq; // {time, {i, j}}

        pq.push({grid[0][0], {0, 0}});
        dist[0][0] = grid[0][0];
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        
        while(!pq.empty()) {
            auto [t, pos] = pq.top(); pq.pop();
            auto [x, y] = pos;
            if(x == n-1 && y == n-1) return t;
            
            for(auto &d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if(nx>=0 && ny>=0 && nx<n && ny<n) {
                    int newT = max(t, grid[nx][ny]);
                    if(newT < dist[nx][ny]) {
                        dist[nx][ny] = newT;
                        pq.push({newT, {nx, ny}});
                    }
                }
            }
        }
        return -1;
    }
};