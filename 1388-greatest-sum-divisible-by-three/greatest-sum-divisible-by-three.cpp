class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int count1=0,count2=0;
        int sum=0;
        int minf1=1e5,mins1=1e5,mins2=1e5,minf2=1e5;
        for(int i=0;i<nums.size();++i){
             if(nums[i]%3==1){
                count1++;
                if(minf1>=nums[i])  {
                    mins1=minf1;
                    minf1=nums[i];
                }else if(mins1>=nums[i]){
                    mins1=nums[i];
                }
            }else if(nums[i]%3==2){
                count2++;
                if(minf2>=nums[i])  {
                    mins2=minf2;
                    minf2=nums[i];
                }else if(mins2>=nums[i]){
                    mins2=nums[i];
                }
            }
            sum+=nums[i];
        }
        int d1=minf1+mins1;
        int d2=minf2+mins2;
        if(sum%3==0) return sum;
        else if(sum%3==1){
            if(count1>=1){
                return sum-min(minf1,d2);
            }else{
                return sum-d2;
            }
        }
        else{
            if(count2>=1)
                return sum-min(minf2,d1);
            else 
            return sum-d1;
        }

    }
};