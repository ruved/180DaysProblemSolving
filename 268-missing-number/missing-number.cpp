class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i=0;
        for(int j=0;j<nums.size();++j)
        {
            i=i^(j+1)^(nums[j]);
        }
        return i;
    }
};