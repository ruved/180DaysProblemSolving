class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,int>mp;
        int mod=1e9+7;
        for(int i=1;i<nums.size();++i)
            mp[nums[i]]++;
        unordered_map<int,int>left;
        left[nums[0]]=1;
        int ans=0;
        for(int i=1;i<nums.size();++i){
            mp[nums[i]]--;
            if(mp.find(2*nums[i])!=mp.end()&&left.find(2*nums[i])!=left.end()){
                long temp=1;
                temp=mp[2*nums[i]]*1L*left[2*nums[i]];
                temp%=mod;
                ans=(ans%mod+temp%mod)%mod;
            }
            left[nums[i]]++;
        }
        return ans;
    }
};