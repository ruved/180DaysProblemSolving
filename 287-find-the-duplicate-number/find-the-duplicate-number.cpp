class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // int x=1^nums[0];
        // for(int i=1;i<nums.size();++i)
        //     x^=(i+1)^nums[i];
        //     int a=0,b=0;
        //     while(x)
        //     {
        //         if(x&1)
        //         {
        //             a
        //         }
        //     }
        // return x;
        unordered_set<int>st;
        for(int i=0;i<nums.size();++i)
        {
            if(st.find(nums[i])!=st.end())
            return nums[i];
            st.insert(nums[i]);
        }
        return 0;
    }
};