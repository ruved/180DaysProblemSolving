class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int>mp;
        int sum=-1;
        int d=0;
        for(int i=0;i<nums.size();++i){
            d=0;
            int k=nums[i];
            while(k){
                d+=k%10;
                k/=10;
            }
            if(mp.find(d)!=mp.end()){
                sum=max(sum,mp[d]+nums[i]);
                if(mp[d]<nums[i])
                    mp[d]=nums[i];
            }
            else{
                mp[d]=nums[i];
            }
        }
        return sum;
    }
};