class Solution {
public:
    int minimumDistance(vector<int>& nums) {
         unordered_map<int,vector<int>>mp;
        int ans=INT_MAX;
        for(int i=0;i<nums.size();++i){
            mp[nums[i]].push_back(i);
            if(mp[nums[i]].size()>=3){
                int n=mp[nums[i]].size()-1;
                int sum=2*(mp[nums[i]][n]-mp[nums[i]][n-2]);
                ans=min(ans,sum);
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};