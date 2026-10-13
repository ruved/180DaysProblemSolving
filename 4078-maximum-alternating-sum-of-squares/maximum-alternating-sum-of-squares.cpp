class Solution {
public:
bool static cmp(int &a,int &b){
    return abs(a)<abs(b);
}
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        int i=0;
        int j=nums.size()-1;
        long long ans=0;
        while(i<=j){
            ans+=abs(nums[j]*nums[j]);
            j--;
            if(i>j) break;
            ans-=abs(nums[i]*nums[i]);
            i++;
        }
        return ans;
    }
};