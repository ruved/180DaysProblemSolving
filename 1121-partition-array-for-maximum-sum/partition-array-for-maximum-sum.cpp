class Solution {
public:
int help(vector<int>& arr, int &k,int i,vector<int>&dp){
    if(i>=arr.size()) return 0;
    if(dp[i]!=-1) return dp[i];
    int maxEle=0;
    int res=0;
    for(int j=i;j<(i+k)&&j<arr.size();++j){
        maxEle=max(maxEle,arr[j]);
        int temp=maxEle*(j-i+1);
        res=max(res,temp+help(arr,k,j+1,dp));
    }
    return dp[i]=res;
}

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n,-1);
        return help(arr,k,0,dp);
    }
};