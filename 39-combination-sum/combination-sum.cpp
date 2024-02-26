class Solution {
public:
    void  help(vector<int>& candidates, int target,int i,vector<int>&temp,vector<vector<int>>&ans)
    {
        if(i<0) return ;
        if(target==0)
        {
            if(temp.size()>0)
            ans.push_back(temp);
            return ;
        }
       
        if(target>=candidates[i])
        {
            temp.push_back(candidates[i]);
            help(candidates,target-candidates[i],i,temp,ans);
            temp.pop_back();
        }
        help(candidates,target,i-1,temp,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>temp;
        vector<vector<int>>ans;
         help(candidates,target,candidates.size()-1,temp,ans);
        return ans;
    }
};