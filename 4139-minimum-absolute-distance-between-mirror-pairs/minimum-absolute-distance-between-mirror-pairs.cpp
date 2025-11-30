class Solution {
public:
    int reverse(int num){
        int res=0;
        while(num){
            res=res*10+num%10;
            num/=10;
        }
        return res;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans=INT_MAX;
        for(int i=0;i<nums.size();++i){
            
            if(mp.find(nums[i])!=mp.end()){
                ans=min(ans,i-mp[nums[i]]);
            }
            int temp=reverse(nums[i]);
            while(temp%10==0) temp/=10;
            mp[temp]=i;
        }
        return ans==INT_MAX?-1:ans;
    }
};