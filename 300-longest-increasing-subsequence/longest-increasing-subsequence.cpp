class Solution {
public:
// int help(vector<int>& nums,int i,int prev,vector<vector<int>>&dp){
//     if(i==nums.size()) return 0;
//     if(dp[prev+1][i]!=-1) return dp[prev+1][i];
//     int take=0;
//     if(prev==-1||nums[prev]<nums[i])
//     take=1+help(nums,i+1,i,dp);
//     int notake=help( nums,i+1,prev,dp);
//     return dp[prev+1][i]=max(take,notake);
// }   
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // vector<vector<int>>dp(n+1,vector<int>(n,0));
        // // return help(nums,0,-1,dp);
        // vector<int>cur(n+1,0);
        // vector<int>pre(n+1,0);
        // cur[0]=1;
        // for(int i=0;i<n-1;++i)
        //     pre[i+1]=nums[i]<nums[n-1]?1:0;
        
        // for(int i=n-2;i>=0;--i){
        //     for(int prev=i-1;prev>=-1;--prev){
        //         int take=0;
        //         if(prev==-1||nums[prev]<nums[i])
        //             take=1+pre[i+1];//dp[i+1][i+1];//help(nums,i+1,i,dp);
        //         int notake=pre[prev+1];//dp[prev+1][i+1];//help(nums,i+1,prev,dp);
        //         cur[prev+1]=max(take,notake);
        //     }
        //     pre=cur;
        // }
        // return cur[0];
        vector<int>st;
        // st.push(nums[0]);
        int ans=1;
        for(int i=0;i<n;++i){
            if(st.empty()||(st[st.size()-1]<nums[i])) 
                st.push_back(nums[i]);
            else{
               auto x=lower_bound(st.begin(),st.end(),nums[i]);
                *x=nums[i];
            }
        }
        return st.size();
    }
};