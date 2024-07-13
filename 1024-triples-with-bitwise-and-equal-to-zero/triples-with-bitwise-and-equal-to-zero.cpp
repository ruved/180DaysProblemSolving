class Solution {
public:

    int countTriplets(vector<int>& nums) {
        int n=nums.size();
       unordered_map<int,int>mp;
       for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            mp[nums[i]&nums[j]]++;
        
        int ans=0;
        for(auto it:mp){
            for(int k=0;k<n;++k){
                if((it.first&nums[k])==0)
                    ans+=it.second;
            }
        }
        return ans;
        
    }
};
