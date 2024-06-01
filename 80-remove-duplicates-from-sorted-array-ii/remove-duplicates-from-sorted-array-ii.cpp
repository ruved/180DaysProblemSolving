class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev=nums[0];
        int count=1;
        int j=1;
        for(int i=1;i<nums.size();++i){
            if(prev!=nums[i]){
                nums[j++]=nums[i];
                count=1;
                prev=nums[i];
            }
            else{
                count++;
                if(count<=2)
                    nums[j++]=nums[i];
                
            }
        }
        return j;
    }
};