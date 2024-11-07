class Solution {
public:

    int largestCombination(vector<int>& candidates) {
        vector<vector<int>>memo(32,vector<int>(candidates.size(),0));
        for(int i=0;i<candidates.size();++i){
            int c=0;
            while(candidates[i]>0){
                if(candidates[i]&1){
                    memo[c][i]=1;
                }
                c++;
                candidates[i]>>=1;
            }
        }
        int ans=0;
        for(int i=0;i<32;++i){
            int res=0;
            for(int j=0;j<candidates.size();++j){
                res+=memo[i][j];
            }
            ans=max(res,ans);
        }
      
        return ans;
    }
};