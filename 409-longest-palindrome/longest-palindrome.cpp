class Solution {
public:
bool static cmp(int &a,int &b){
    return a>b;
}
    int longestPalindrome(string s) {
        vector<int>mp(256,0);
        for(int i=0;i<s.length();++i)
            mp[s[i]]++;
        sort(mp.begin(),mp.end(),cmp);
        int ans=0;
        bool odd=false;
        for(int i=0;i<mp.size();++i){
            ans+=(mp[i]/2)*2;
            if(!odd)
                odd=mp[i]%2;
        }
        ans+=odd?1:0;
        return ans;
    }
};