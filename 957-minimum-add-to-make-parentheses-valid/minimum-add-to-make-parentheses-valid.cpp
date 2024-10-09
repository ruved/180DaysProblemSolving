class Solution {
public:
    int minAddToMakeValid(string s) {
        int left=0;
        int ans=0;
        for(int i=0;i<s.length();++i){
            if(s[i]=='(') left++;
            else left--;
            if(left<0){
                left=0;
                ans++;
            }
        }
        return ans+left;
    }
};