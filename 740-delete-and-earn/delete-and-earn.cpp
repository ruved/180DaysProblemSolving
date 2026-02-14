class Solution {
public:
int help(vector<pair<int,int>>&arr,int i,vector<int>&dp){
    if(i<0) return 0;
    if(i==0) return arr[0].first*arr[0].second;
    if(dp[i]!=-1) return dp[i];

    int cur=arr[i].first*arr[i].second;
    int take=0;
    if(i>0&&arr[i].first==arr[i-1].first+1)
        take=help(arr,i-2,dp);
    else 
        take=help(arr,i-1,dp);
    int skip=help(arr,i-1,dp);

    return dp[i]=max(cur+take,skip);;;
}
    int deleteAndEarn(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();++i) mp[nums[i]]++;
        vector<pair<int,int>>arr;
        for(auto it=mp.begin();it!=mp.end();++it)
            arr.push_back({it->first,it->second});
        
        vector<int>dp(arr.size(),-1);
        return help(arr,arr.size()-1,dp);
    }
};