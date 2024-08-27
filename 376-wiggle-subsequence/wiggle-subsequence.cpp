class Solution {
public:
    int n;
    int dp[2][1005] ; 
   
    int helper(int idx , vector<int>& nums , int sign){
        if(dp[sign][idx] != -1 )    return dp[sign][idx] ; 
        int ans = 1 ; 
        for(int i=idx+1 ; i<n;i++){
            if(sign==1){
                if(nums[i]-nums[idx] > 0){
                    ans = max(ans,1+helper(i , nums , 0)) ; 
                }   
            }
            else{
                if(nums[i]-nums[idx] < 0){
                    ans = max(ans  ,1+helper(i , nums , 1)) ;
                }   
            }
        }
        return dp[sign][idx] =ans ; 
    }
    int wiggleMaxLength(vector<int>& nums) {
        n = nums.size()  ;
        memset(dp , -1 , sizeof(dp)) ;
        int ans = helper(0 , nums , 1) ;   
        ans = max(ans , helper(0,nums , 0)) ; 
        
        return ans ; 
    }
};