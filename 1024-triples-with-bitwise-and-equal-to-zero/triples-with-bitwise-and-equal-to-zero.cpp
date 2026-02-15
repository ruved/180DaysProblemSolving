class Solution {
public:

    int countTriplets(vector<int>& nums) {
        
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();++i)
            for(int j=0;j<nums.size();++j)
                mp[nums[i]&nums[j]]++;

        int ans=0;
        for(auto it:mp){
                if(it.first==0) ans+=(it.second*nums.size());
                else {
                    for(int i=0;i<nums.size();++i)
                        if((it.first&nums[i])==0) ans+=it.second;
                    }   
        }

        return ans;   
    }
};