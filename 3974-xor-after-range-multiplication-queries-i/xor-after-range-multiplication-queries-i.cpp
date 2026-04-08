class Solution {
public:
int mod=1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(int i=0;i<queries.size();++i){
            for(int j=queries[i][0];j<=queries[i][1];j+=queries[i][2])
                nums[j]=(1LL*nums[j]*queries[i][3])%mod;
        }
        int res=nums[0];
        for(int i=1;i<nums.size();++i)
            res^=nums[i];
        return res;
    }
};