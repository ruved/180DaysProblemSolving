class Solution {
public:
    int binarysearch(vector<int>& nums)
    {
        int l=0,r=nums.size()-1;
        int mid;
        while(l<=r)
        {
            mid=l+(r-l)/2;
            if(nums[mid]<0)
                l=mid+1;
            else
                r=mid-1;
        }
        return l;
    }
    vector<int> sortedSquares(vector<int>& nums) {
        int l=binarysearch(nums);
        int j=l-1;
        vector<int>ans;
        
         while(j>=0&&l<nums.size())
         {
             if(nums[j]*nums[j]<=nums[l]*nums[l])
             {
                 ans.push_back(nums[j]*nums[j]);
                 --j;
             }
             else
             {
                 ans.push_back(nums[l]*nums[l]);
                 l++;
             }
         }
        while(j>=0)
        {
             ans.push_back(nums[j]*nums[j]);
                 --j;
        }
         while(l<nums.size())
        {
             ans.push_back(nums[l]*nums[l]);
                 l++;
        }
           return ans; 
    }
};