class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int>freq(nums.size()-2,0);
        vector<int>ans;
        for(int i=0;i<nums.size();++i){
            if(freq[nums[i]]>0) ans.push_back(nums[i]);
            freq[nums[i]]++;
        }
    return ans;
    }
};