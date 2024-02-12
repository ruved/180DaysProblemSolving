class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majelement=nums[0];
        int count=1;
        for(int i=1;i<nums.size();++i)
        {
            if(majelement==nums[i])
                count++;
            else if(count>0)
                count--;
            else
            {
                majelement=nums[i];
                count=1;
            }
        }
        return majelement;
            
    }
};