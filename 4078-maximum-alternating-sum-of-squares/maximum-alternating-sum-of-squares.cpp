class Solution {
public:
static bool cmp(int &a,int &b){
    return abs(a)<abs(b);
}
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        int i=0;
        int j=nums.size()-1;
        long long res=0;
        while(i<=j){
            res+=nums[j]*nums[j];
            j--;
            if(i<=j){
                res=res-(nums[i]*nums[i]);
                i++;
            }
        }
        return res;
    }
};