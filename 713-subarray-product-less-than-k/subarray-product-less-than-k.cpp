class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0;
       int j=0;
            int res=1;
            for(int i=0;i<nums.size();++i)
            {
                res=res*nums[i];
                
                while(j<=i&&res>=k)
                {
                    res/=nums[j++];
                }
                ans+=i-j+1;
            }
        
        return ans;
    }
};