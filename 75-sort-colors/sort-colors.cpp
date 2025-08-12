class Solution {
public:

    void sortColors(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        int mid=0;
        while(mid<=r){
            if(nums[mid]==0){
               int t=nums[l];
               nums[l]=nums[mid];
               nums[mid]=t;
                l++;
                mid++;
            }else if(nums[mid]==2){
                int t=nums[r];
               nums[r]=nums[mid];
               nums[mid]=t;
                r--;
            }else mid++;
           
        }
    }
};