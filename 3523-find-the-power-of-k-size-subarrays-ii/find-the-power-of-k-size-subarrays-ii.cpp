class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>res(n-k+1,-1);
        int count=0;
        for(int i=1;i<k;++i){
            if(nums[i]==nums[i-1]+1)
            count++;
        }
        if(count==k-1)
        res[0]=nums[k-1];
        int j=0;
        for(int i=k;i<n;++i){
            if(nums[i]==nums[i-1]+1)
                count++;
            if(nums[j]==nums[j+1]-1)
            count--;
            if(count==k-1)
            res[i-k+1]=nums[i];
            j++;
        }
        return res;
    }
};