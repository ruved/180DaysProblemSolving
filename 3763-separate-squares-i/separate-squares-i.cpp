class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double totalArea = 0.0;
        double low = 1e18, high = -1e18;

        // Compute total area and y-range
        for (auto &sq : squares) {
            double y = sq[1];
            double l = sq[2];
            totalArea += l * l;
            low = min(low, y);
            high = max(high, y + l);
        }

        double target = totalArea / 2.0;

        // Binary search on y
        for (int iter = 0; iter < 70; iter++) { // sufficient for 1e-5 precision
            double mid = (low + high) / 2.0;
            double areaAbove = 0.0;

            // Compute area above mid
            for (auto &sq : squares) {
                double y = sq[1];
                double l = sq[2];
                double top = y + l;

                if (mid <= y) {
                    areaAbove += l * l;
                } else if (mid >= top) {
                    continue;
                } else {
                    areaAbove += l * (top - mid);
                }
            }

            if (areaAbove > target) {
                low = mid;
            } else {
                high = mid;
            }
        }

        return (low + high) / 2.0;
    }
};