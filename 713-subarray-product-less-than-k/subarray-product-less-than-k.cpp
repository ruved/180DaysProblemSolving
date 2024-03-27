class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0;
        for(int i=0;i<nums.size();++i)
        {
            int res=1;
            for(int j=i;j<nums.size();++j)
            {
                res=res*nums[j];
                if(res>=k)
                    break;
                ans++;
            }
        }
        return ans;
    }
};