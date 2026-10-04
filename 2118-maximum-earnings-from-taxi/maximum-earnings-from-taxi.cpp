class Solution {
public:
    int binary(vector<vector<int>>& rides, int i, int endt) {
        int l = i + 1;
        int r = rides.size() - 1;
        int ans = rides.size();
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (rides[mid][0] >= endt) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        // 1. Sort by start time
        sort(rides.begin(), rides.end());
        int M = rides.size();
        
        // 2. Initialize DP array
        vector<long long> dp(M + 1, 0);
        
        // 3. Iterate backwards
        for (int i = M - 1; i >= 0; i--) {
            long long profit = rides[i][1] - rides[i][0] + rides[i][2];
            
            // Find next valid ride using the end time of current ride
            int j = binary(rides, i, rides[i][1]); 
            
            // DP Transition: Max of skipping or taking
            dp[i] = max(dp[i + 1], profit + dp[j]);
        }
        
        return dp[0]; 
    }
};