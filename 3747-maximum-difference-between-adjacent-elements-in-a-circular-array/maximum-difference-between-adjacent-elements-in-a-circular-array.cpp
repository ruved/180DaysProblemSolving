class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int ans=INT_MIN;
        for(int i=1;i<nums.size();++i){
            ans=max(ans,abs(nums[i]-nums[i-1]));
        }
        int l=nums.size()-1;
        ans=max(ans,abs(nums[0]-nums[l]));
        return ans;
    }
};