class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long>ans;
        int mod=1e9+7;
        for(int i=0;i<nums.size();++i)
        {
            int tmp=0;
            for(int j=i;j<nums.size();++j){
                tmp+=nums[j];
                ans.push_back(tmp);
            }
        }
        sort(ans.begin(),ans.end());
        long int res=0;
        for(int i=left-1;i<right;++i){
            res+=ans[i];
            res%=mod;
        }
        return res;
    }
};