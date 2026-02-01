class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int sum=nums[0];
        int ans=INT_MAX;
        for(int i=1;i<nums.size()-1;++i)
        {
            for(int j=i+1;j<nums.size();++j)
                ans=min(ans,sum+nums[i]+nums[j]);
        }
        return ans;
    }
};