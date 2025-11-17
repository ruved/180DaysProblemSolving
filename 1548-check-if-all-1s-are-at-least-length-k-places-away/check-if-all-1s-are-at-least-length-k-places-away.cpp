class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int i=0;
        int d=0;
        while(i<nums.size()){
            if(nums[i]==1){
                if(d<=0) d=k;
                else
                return false;
            }else{
                d--;
            }
            i++;
        }
        return true;
    }
};