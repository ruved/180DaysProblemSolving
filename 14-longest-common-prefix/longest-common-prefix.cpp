class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        
        for(int j=0;j<strs[0].length();++j)
        {
            char pre=strs[0][j];
            for(int i=1;i<strs.size();++i){
                
                if(pre!=strs[i][j])
                return ans;
            }
            ans+=pre;
        }
        return ans;
    }
};