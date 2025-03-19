class Solution {
public:
   int ans=0;  
    int minOperations(vector<int>& nums) {
        int ans=0;
        int n=nums.size()-1;
        for(int i=0;i<nums.size()-2;++i){
            if(nums[i]==0){
                for(int j=i;j<i+3;++j){
                    if(nums[j]==0)
                        nums[j]=1;
                    else
                        nums[j]=0;
                }
                ans++;
            }
        }
        if(nums[n]==1&&nums[n-1]==1) return ans;
        return -1;
    }
};