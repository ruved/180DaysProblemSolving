class Solution {
public:
    int minOperations(string s) {
        int freq[26]={0};
        for(int i=0;i<s.length();++i)
            freq[s[i]-'a']++;
            int ans=0;
        for(int i=1;i<25;++i){
            if(freq[i]>0){
                 ans++;
                 freq[i+1]+=freq[i];
            }  
        }
        if(freq[25]>0) ans++;
        return ans;
    }
};