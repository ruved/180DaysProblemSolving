class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        map<int,int>mp;
        for(int i=0;i<nums.size();++i){
            mp[nums[i]]++;
        }
        int n=nums.size();
        int count=0;
        int ans=0;
        for(auto it=mp.begin();it!=mp.end();++it){
            count+=(it->second);
            cout<<count<<" ";
            if((n-count)>=k) ans+=it->second;
        }
        return ans;
    }
};