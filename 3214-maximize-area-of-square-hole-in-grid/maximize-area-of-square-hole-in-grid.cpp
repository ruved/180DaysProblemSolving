class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        std::sort(hBars.begin(), hBars.end());
        std::sort(vBars.begin(), vBars.end());

        // Find max consecutive horizontal bars
        int maxH = 1, currH = 1;
        for (int i = 1; i < hBars.size(); ++i) {
            if (hBars[i] == hBars[i - 1] + 1) currH++;
            else currH = 1;
            maxH = std::max(maxH, currH);
        }

        // Find max consecutive vertical bars
        int maxV = 1, currV = 1;
        for (int i = 1; i < vBars.size(); ++i) {
            if (vBars[i] == vBars[i - 1] + 1) currV++;
            else currV = 1;
            maxV = std::max(maxV, currV);
        }

        // The gap length is (number of consecutive bars + 1)
        // The square side is the minimum of the two possible gaps
        int side = std::min(maxH + 1, maxV + 1);

        return side * side;
    }
};