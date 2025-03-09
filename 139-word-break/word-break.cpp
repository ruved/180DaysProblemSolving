class Solution {
public:
bool help(string &s, unordered_set<string>&dict,int i,vector<int>&dp){
    if(i>=s.length()) return true;
    if(dp[i]!=-1) return dp[i];
    bool ans=false;
    string str="";
    for(int j=i;j<s.length();++j){
        str.push_back(s[j]);
        if(dict.find(str)!=dict.end()){
            ans|=help(s,dict,j+1,dp);
        }
    }
    return dp[i]=ans;
}
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>dict;
        vector<int>dp(s.length(),-1);
        for(int i=0;i<wordDict.size();++i)
            dict.insert(wordDict[i]);
        return help(s,dict,0,dp);
    }
};