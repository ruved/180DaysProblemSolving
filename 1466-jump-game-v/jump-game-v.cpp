class Solution {
public:

    int n;
    vector<int> dp;

    int dfs(vector<int>& arr,
            int i,
            int d) {

        if(dp[i] != -1)
            return dp[i];

        int ans = 1;

        // RIGHT
        for(int j = i+1;
            j <= min(n-1, i+d);
            j++) {

            // barrier
            if(arr[j] >= arr[i])
                break;

            ans = max(ans,
                      1 + dfs(arr,j,d));
        }

        // LEFT
        for(int j = i-1;
            j >= max(0, i-d);
            j--) {

            // barrier
            if(arr[j] >= arr[i])
                break;

            ans = max(ans,
                      1 + dfs(arr,j,d));
        }

        return dp[i] = ans;
    }

    int maxJumps(vector<int>& arr, int d) {

        n = arr.size();

        dp.assign(n,-1);

        int ans = 1;

        for(int i = 0; i < n; i++) {

            ans = max(ans,
                      dfs(arr,i,d));
        }

        return ans;
    }
};