class Solution {
public:
int ans=0;
void help(vector<int>& nums,int i,int temp){

    if(i<0){
            if(temp!=-1)
                ans+=temp;
            return ;
    }
    help(nums,i-1,(temp==-1?nums[i]:temp^nums[i]));
    help(nums,i-1,temp);
}
    int subsetXORSum(vector<int>& nums) {
        help(nums,nums.size()-1,-1);
        return ans;
    }
};