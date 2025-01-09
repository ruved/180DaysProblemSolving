class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int t=pref.length();
        int ans=0;
        for(int i=0;i<words.size();++i){
            if(words[i].length()>=t){
                string temp=words[i].substr(0,t);
                if(temp==pref) ans++;
            }
        }
        return ans;
    }
};