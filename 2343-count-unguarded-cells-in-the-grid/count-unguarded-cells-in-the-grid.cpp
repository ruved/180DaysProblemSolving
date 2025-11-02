class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
       const int EMPTY = 0, WALL = 1, GUARD = 2, GUARDED = 3;

        vector<vector<int>> grid(m, vector<int>(n, EMPTY));

        // Mark walls and guards
        for (auto &w : walls)
            grid[w[0]][w[1]] = WALL;

        for (auto &g : guards)
            grid[g[0]][g[1]] = GUARD;

        // Directions: up, down, left, right
        vector<pair<int,int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        // Spread guard vision
        for (auto &g : guards) {
            int gr = g[0], gc = g[1];
            for (auto &[dr, dc] : dirs) {
                int r = gr + dr, c = gc + dc;
                while (r >= 0 && r < m && c >= 0 && c < n &&
                       grid[r][c] != WALL && grid[r][c] != GUARD) {
                    if (grid[r][c] == EMPTY)
                        grid[r][c] = GUARDED;
                    r += dr;
                    c += dc;
                }
            }
        }

        // Count unguarded cells
        int count = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == EMPTY)
                    count++;

        return count;
        
    }
};