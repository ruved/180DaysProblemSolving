class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size();
        bool hasg=false;
        int mx = INT_MIN;
        for(auto &i: arr) {
            mx = max(mx, i);
            if (i>=0) hasg = true; 
        }
        if (!hasg) {
            return mx; // if only negative elements are there
        }
        vector<int> dp(n+1, 0), del(n+1, 0);
        mx = INT_MIN;
        for(int i=1; i<=n; i++) {
            dp[i] = max(dp[i-1] + arr[i-1], arr[i-1]);
            del[i] = max({del[i-1] + arr[i-1], dp[i-1], arr[i-1]});
            mx = max(mx, del[i]);
        }
        return mx;
    }
};