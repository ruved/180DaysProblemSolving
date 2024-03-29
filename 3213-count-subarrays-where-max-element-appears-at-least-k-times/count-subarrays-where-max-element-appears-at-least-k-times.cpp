class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxele=*max_element(nums.begin(),nums.end());
        int mcount=0;
        int j=0;
        long long ans=0;
        int n=nums.size();
        for(int i=0;i<n;++i)
        {
            if(nums[i]==maxele)
                mcount++;
            while(j<=i&&mcount>=k)
            {
                ans+=(n-i);
                if(nums[j]==maxele)
                    mcount--;
                j++;
            }
        }
        return ans;
    }
};