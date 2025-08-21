class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const int INF = 1e9;
        vector<vector<int>> dist(m, vector<int>(n, INF));
        using State = pair<int,pair<int,int>>; // {cost, {x,y}}
        priority_queue<State, vector<State>, greater<State>> pq;

        auto inb = [&](int x, int y){ return 0<=x && x<m && 0<=y && y<n; };
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1,-1, 0,  0};
        int code[4]= {1, 2, 3,  4};

        dist[0][0] = 0;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            auto [d, p] = pq.top(); pq.pop();
            int x = p.first, y = p.second;
            if(d != dist[x][y]) continue; // stale
            if(x==m-1 && y==n-1) return d;

            for(int k=0;k<4;k++){
                int nx=x+dx[k], ny=y+dy[k];
                if(!inb(nx,ny)) continue;
                int w = (grid[x][y]==code[k]) ? 0 : 1;
                if(dist[nx][ny] > d + w){
                    dist[nx][ny] = d + w;
                    pq.push({dist[nx][ny], {nx,ny}});
                }
            }
        }
        return dist[m-1][n-1];
    }
};