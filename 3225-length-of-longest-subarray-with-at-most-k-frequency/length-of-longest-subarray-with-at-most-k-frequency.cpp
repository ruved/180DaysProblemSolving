class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        set<pair<int,int>>st;
        unordered_map<int,int>mp;
        int len=0;
        int j=0;
        for(int i=0;i<nums.size();++i)
        {
            st.erase({mp[nums[i]],nums[i]});
            mp[nums[i]]++;
            st.insert({mp[nums[i]],nums[i]});
            while(j<=i&&(*st.rbegin()).first>k)
            {
                st.erase({mp[nums[j]],nums[j]});
                mp[nums[j]]--;
                if(mp[nums[j]]==0)
                mp.erase(nums[j]);
                else
                st.insert({mp[nums[j]],nums[j]});
                j++;
            }
            len=max(len,i-j+1);
        }
        return len;
    }
};