class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini=min_element(nums.begin(),nums.end())-nums.begin();
        int maxi=max_element(nums.begin(),nums.end())-nums.begin();
        int st=min(mini,maxi);
        int en=max(mini,maxi);
        int len=nums.size();
        int ans=0;
        if(st>=len-1-en){
            ans+=len-en;
            ans+=min(en-st,st+1);
        }
        else{
            ans+=st+1;
            ans+=min(en-st,len-en);
        }
        return ans;

    }
};