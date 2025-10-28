class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();++i){
            sum+=nums[i];
        }
        int left=0;
        int ans=0;
        for(int i=0;i<nums.size();++i){
            left+=nums[i];
            if(nums[i]==0){
               int right=sum-left;
                if(abs(right-left)==1)
                ans++;
                else if(right==left) ans+=2;
            }
        }
        return ans;
    }
};