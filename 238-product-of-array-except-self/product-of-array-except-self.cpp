class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long product=1;
        int czero=0,pos=0;
        for(int i=0;i<nums.size();++i)
        {   if(nums[i]!=0)
            product*=nums[i];
            else{pos=i;
                czero++;}
        }
        
        vector<int>ans(nums.size(),0);
        if(czero==1){
                ans[pos]=product;
        } 
        else if(czero==0){
            for(int i=0;i<nums.size();++i)
                    ans[i]=product/nums[i];              
        }
        return ans;
    }
};