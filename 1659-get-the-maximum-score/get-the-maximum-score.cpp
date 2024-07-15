class Solution {
public:
long mod=1000000007;
    long long  help(vector<int>& nums1, vector<int>& nums2,bool first,int i,unordered_map<int,int>&mp1,unordered_map<int,int>&mp2,
    vector<vector<long long int>>&dp){
        if(i<0) return 0;
        
        if(dp[first][i]!=-1) return dp[first][i];
        long long int ans=0;
        long long int l1=0,l2=0;
        if(first){
            if(mp2.find(nums1[i])!=mp2.end())
                l1=help(nums1,nums2,false,mp2[nums1[i]]-1,mp1,mp2,dp);
            ans=nums1[i];
        }else{
            if(mp1.find(nums2[i])!=mp1.end())
                l1=help(nums1,nums2,true,mp1[nums2[i]]-1,mp1,mp2,dp);
                ans=nums2[i];
        }
        l2=help(nums1,nums2,first,i-1,mp1,mp2,dp);
        long long  res=(ans+max(l1,l2));
        return dp[first][i]=res;

    }
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp1,mp2;

        for(int i=0;i<nums1.size();++i)
            mp1[nums1[i]]=i;
        for(int i=0;i<nums2.size();++i)
            mp2[nums2[i]]=i;
        int n=nums1.size();
        int m=nums2.size();
        int s=max(n,m);
        vector<vector<long long int>>dp(2,vector<long long int>(s+1,-1));
        return max(help(nums1,nums2,true,n-1,mp1,mp2,dp),help(nums1,nums2,false,m-1,mp1,mp2,dp))%mod;
    }
};