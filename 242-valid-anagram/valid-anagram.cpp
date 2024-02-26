class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        
        vector<int> mp(26,0);
        for(int i=0;i<s.length();++i)
        {
            mp[s[i]-'a']++;
            mp[t[i]-'a']--;
        }
        for(int i=0;i<t.length();++i)
            if(mp[t[i]-'a']!=0) return false;
        return true;
        
    }
};