class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        for(int k=0;k<n-2;++k)
        {
            int i=k+1;
            int j=n-1;
            while(i<j)
            {
                if(0==(nums[i]+nums[j]+nums[k]))
                {
                    st.insert({nums[k],nums[i],nums[j]});
                    i++;j--;
                while (i < j && nums[i] == nums[i - 1]) i++;
                while (i < j && nums[j] == nums[j + 1]) j--;
                }
                else if(0<(nums[i]+nums[j]+nums[k]))
                j--;
                else
                i++;
            }
        }
        vector<vector<int>> ans;
        for(auto it=st.begin();it!=st.end();++it)
        {
            ans.push_back(*it);
        }
        return ans;
    }
};