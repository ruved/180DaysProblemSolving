class Solution {
public:
int help(vector<vector<int>>&arr,int i,vector<int>&dp){
    if(i<0) return 0;
    if(dp[i]!=-1) return dp[i];
    int ans=arr[i][2];
    for(int j=i-1;j>=0;--j){
        if(arr[i][0]>=arr[j][1])
            ans=max(ans,arr[i][2]+help(arr,j,dp));
    }
    return dp[i]=ans;
}
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        // vector<vector<int>>arr;
        // for(int i=0;i<startTime.size();++i)
        //     arr.push_back({startTime[i],endTime[i],profit[i]});
        // sort(arr.begin(),arr.end());
        // vector<int>dp(arr.size(),-1);
        // int result = 0;
        // for(int i = 0; i < arr.size(); i++) {
        //     result = max(result, help(arr,i, dp));
        // }

        // return result;
        int n = startTime.size();
        vector<array<int,3>> jobs;

        for(int i = 0; i < n; i++)
            jobs.push_back({startTime[i], endTime[i], profit[i]});

        // Sort by end time
        sort(jobs.begin(), jobs.end(),
             [](auto &a, auto &b){
                 return a[1] < b[1];
             });

        vector<int> dp(n);
        vector<int> endTimes;

        for(int i = 0; i < n; i++)
            endTimes.push_back(jobs[i][1]);

        dp[0] = jobs[0][2];

        for(int i = 1; i < n; i++) {
            int take = jobs[i][2];

            // binary search find the largest j<i for which end[j]<=start[i] 
            int j = upper_bound(endTimes.begin(), endTimes.end(),
                                    jobs[i][0]) - endTimes.begin() - 1;

            if(j >= 0)
                take += dp[j];

            dp[i] = max(dp[i-1], take);
        }

        return dp[n-1];
    }
};