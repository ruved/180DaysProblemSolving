class Solution {
public:
int help(vector<int>& nums,int i,unordered_map<int,int>&mp,vector<int>&dp){
    if(i<0) return 0;
    if(dp[i]!=-1) return dp[i];
    int take=0,notake=0;
    if((i-1)>=0&&nums[i]-1==nums[i-1])
        take=mp[nums[i]]*nums[i]+help(nums,i-2,mp,dp);
    else
        take=mp[nums[i]]*nums[i]+help(nums,i-1,mp,dp);
    
    notake=help(nums,i-1,mp,dp);
    return dp[i]=max(take,notake);
}
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;++i) mp[nums[i]]++;

        vector<int>ar;
        for(auto it:mp)
            ar.push_back(it.first); 
        sort(ar.begin(),ar.end());
        vector<int>dp(ar.size(),-1);
       return help(ar,ar.size()-1,mp,dp);
    }
};