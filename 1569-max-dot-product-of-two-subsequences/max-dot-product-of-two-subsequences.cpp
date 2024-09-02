class Solution {
public:
int neg=-1e6-7;
int help(vector<int>& nums1, vector<int>& nums2,int i,int j,vector<vector<int>>&dp){
    if(i<0||j<0) return 0;

    if(dp[i][j]!=INT_MIN) return dp[i][j];

    int take=0;
    for(int k=j;k>=0;--k){
        int temp=nums1[i]*nums2[k]+help(nums1,nums2,i-1,k-1,dp);
        take=max(take,temp);
    }
    int notake=help(nums1,nums2,i-1,j,dp);
    return dp[i][j]=max(take,notake);
}
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>>dp(n,vector<int>(m,INT_MIN));
       int ans= help(nums1,nums2,n-1,m-1,dp);
       if(ans==0){
            int a = *max_element(nums1.begin(), nums1.end());
            int b = *min_element(nums1.begin(), nums1.end());
           
            int c = *max_element(nums2.begin(), nums2.end());
            int d = *min_element(nums2.begin(), nums2.end());
           return max(a*d, b*c);
        }
        return  ans;
    }
};




