class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
               int moveX[4] = {0, 1, 0, -1};
        int moveY[4] = {1, 0, -1, 0};
        // north 0, east 1, south 2, west 4
        set<pair<int, int>> st;
        for (auto it : obstacles) {
            st.insert({it[0], it[1]});
        }
        int x_start = 0, y_start = 0, direction = 0;
        int maxi = 0;
        for (auto it : commands) {
            // turn west
            if (it == -2) {
                direction = (direction + 3) % 4;
            }
            // turn east
            if (it == -1) {
                direction = (direction + 1) % 4;
            }
            // move required steps
            else {
                int moves = it;
                while (moves > 0) {
                    int x_new = x_start + moveX[direction];
                    int y_new = y_start + moveY[direction];

                    if (st.find({x_new, y_new}) == st.end()) {
                        x_start = x_new;
                        y_start = y_new;
                        moves--;
                        maxi = max(maxi, ((x_start*x_start)+(y_start*y_start)));
                    }
                    else{
                        break;
                    }
                }
            }
        }
        return maxi;

    }
};