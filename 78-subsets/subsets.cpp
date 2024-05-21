class Solution {
public:
void help(vector<int>& nums,int i,vector<int>temp,set<vector<int>>&ans){
    if(i<0){
        sort(temp.begin(),temp.end());
        ans.insert(temp);
        return ;
    }

    help(nums,i-1,temp,ans);
    temp.push_back(nums[i]);
    help(nums,i-1,temp,ans);
    temp.pop_back();
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        set<vector<int>>ans;
        help(nums,nums.size()-1,temp,ans);
        vector<vector<int>>res;
        for(auto it:ans)
        {
            res.push_back(it);
        }
        return res;
    }
};