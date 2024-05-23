class Solution {
public:
    int help(vector<int>& nums, int &k,int i,unordered_map<int,int>&mp){
        if(i<0) { return 1; }

        int take=0,ntake=0;
        if(!mp[nums[i]-k] && !mp[k+nums[i]]){
            mp[nums[i]]++;
            take=help(nums,k,i-1,mp);
            mp[nums[i]]--;
        }
        ntake=help(nums,k,i-1,mp);
        return take+ntake;

    }
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        return  help(nums,k,nums.size()-1,mp)-1;      
    }
};