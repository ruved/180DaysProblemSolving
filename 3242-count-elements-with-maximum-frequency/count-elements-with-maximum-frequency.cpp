class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int>arr(101,0);
        for(int i=0;i<nums.size();++i)
        {
            arr[nums[i]]++;
        }
        int ans=0,freq=0;
        for(int i=1;i<=100;++i)
        {
            if(arr[i]>freq)
            {
                freq=arr[i];
                ans=arr[i];
            }
            else if(arr[i]==freq)
                ans+=arr[i];
        }
        return ans;
        
    }
};