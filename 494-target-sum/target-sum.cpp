class Solution {
public:
int help(vector<int>& nums, int target,int i){
    if(i<0){
        if(target==0) return 1;
        else return 0;
    }
    return help(nums,target-nums[i],i-1)+help(nums,target+nums[i],i-1);
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size()-1;
        return help(nums,target,n);
    }
};