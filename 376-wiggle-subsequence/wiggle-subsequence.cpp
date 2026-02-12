class Solution {
public:
int help(vector<int>& nums,int prev,bool pos,vector<vector<int>>&dp){
    if(prev<=0) return prev;
    if(dp[prev][pos]!=-1) return dp[prev][pos];
     int len=0;
    for(int j=prev-1;j>=0;--j){
        if(pos==((nums[prev]-nums[j])<0)&&nums[prev]!=nums[j])
            len=max(len,1+help(nums,j,!pos,dp));
    }
   
    return dp[prev][pos]=len;

}
    int wiggleMaxLength(vector<int>& nums) {
          int n = nums.size();
        if(n < 2) return n;

        vector<int> up(n, 1), down(n, 1);

        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i-1]) {
                up[i] = down[i-1] + 1;
                down[i] = down[i-1];   // carry forward
            }
            else if(nums[i] < nums[i-1]) {
                down[i] = up[i-1] + 1;
                up[i] = up[i-1];       // carry forward
            }
            else {
                up[i] = up[i-1];
                down[i] = down[i-1];
            }
        }

        return max(up[n-1], down[n-1]);
    
    }
};