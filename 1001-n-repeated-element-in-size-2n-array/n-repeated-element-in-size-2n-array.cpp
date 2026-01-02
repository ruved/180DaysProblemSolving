class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        vector<bool>mp(50001,false);
        for(int i=0;i<nums.size();++i){
            if(mp[nums[i]]) return nums[i];
            mp[nums[i]]=true;
        }
        return -1;
    }
};