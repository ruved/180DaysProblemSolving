class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans=0;
       int j=0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();++i)
        {
            mp[nums[i]]++;
            if(mp.size()==k)
            {   
                int l=j;
                vector<int>temp;
                while(l<=i&&mp.size()==k)
                {
                    temp.push_back(nums[l]);
                    mp[nums[l]]--;
                    if(mp[nums[l]]==0)
                    mp.erase(nums[l]);
                    l++;
                    ans++;
                } 
                for(int t:temp)
                    mp[t]++;
            }
            else if(mp.size()>k)
                {
                    while(j<=i&&mp.size()>k)
                    {
                        mp[nums[j]]--;
                        if(mp[nums[j]]==0) mp.erase(nums[j]);
                        j++;
                    }
                int l=j;
                vector<int>temp;
                while(l<=i&&mp.size()==k)
                {
                    temp.push_back(nums[l]);
                    mp[nums[l]]--;
                    if(mp[nums[l]]==0)
                    mp.erase(nums[l]);
                    l++;
                    ans++;
                } 
                for(int t:temp)
                    mp[t]++;
                }
        }
        
       
        return ans;
    }
};