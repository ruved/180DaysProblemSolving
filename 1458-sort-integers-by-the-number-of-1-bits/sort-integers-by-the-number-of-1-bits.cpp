class Solution {
public:
    vector<int> sortByBits(vector<int>& nums) {
        vector<int>arr=nums;
        vector<pair<int,int>>bits(arr.size(),{0,0});

        for(int i=0;i<32;++i)
        {
            for(int j=0;j<arr.size();++j){
                int x=bits[j].first+(arr[j]%2==1);
                bits[j]={x,nums[j]};
                arr[j]/=2;
            }
        }

        sort(bits.begin(),bits.end());
        vector<int>ans;
        for(int i=0;i<bits.size();++i){
            // cout<<bits[i].first<<" "<<bits[i].second<<"::";
            ans.push_back(bits[i].second);
        }
        return ans;
    }
};