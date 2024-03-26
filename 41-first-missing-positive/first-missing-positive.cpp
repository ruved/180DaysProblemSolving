class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
         vector<bool>vis(nums.size(),false);
      int minele=INT_MAX;
      for(int i=0;i<nums.size();++i)
        if(nums[i]>0&&minele>nums[i])
            minele=nums[i];
        if(minele>1) return 1;
      int msize=nums.size();
      for(int i=0;i<nums.size();++i)
      {
        if(nums[i]>0)
        {
           if((nums[i]-minele)>=0&&(nums[i]-minele<msize))
           vis[nums[i]-minele]=true; 
        }
      }
      for(int i=0;i<msize;++i)
      {
        if(!vis[i])
        return minele+i;
      }
      return msize+1;
    }
};