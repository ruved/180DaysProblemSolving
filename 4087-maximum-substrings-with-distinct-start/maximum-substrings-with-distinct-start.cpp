class Solution {
public:
    int maxDistinct(string s) {
        int alpha[26]={0};
        for(int i=0;i<s.length();++i){
            alpha[s[i]-'a']++;
        }
        int ans=0;
        for(int i=0;i<26;++i){
            if(alpha[i]>0) ans++;
        }
        return ans;
    }
};