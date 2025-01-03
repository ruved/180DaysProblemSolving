class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum=0;
        for(int i=0;i<nums.size();++i) sum+=nums[i];
        int ans=0;
        long long left=0;
        for(int i=0;i<nums.size()-1;++i){
            left+=nums[i];
            sum-=nums[i];
            if(left>=sum) ans++;
        }
        return ans;
    }
};