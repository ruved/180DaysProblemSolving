class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
       int prev = 0;
        int res = 0;

        for (int w : weight) {
            if (w < prev) {
                res++;
                prev = 0;
            } else {
                prev = w;
            }
        }

        return res;
    }
};