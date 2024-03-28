class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
       ;
        unordered_map<int,int>mp;
        int len=0;
        int j=0;
        for(int i=0;i<nums.size();++i)
        {
            mp[nums[i]]++;
            while(j<=i&&mp[nums[i]]>k)
            {
                mp[nums[j]]--;
                if(mp[nums[j]]==0)
                mp.erase(nums[j]);
                j++;
            }
            len=max(len,i-j+1);
        }
        return len;
    }
};