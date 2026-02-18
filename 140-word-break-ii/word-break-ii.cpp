class Solution {
public:
void help(string &s,int i,unordered_set<string>&hset,string temp,vector<string>&res){
    if(i>=s.length()){
        res.push_back(temp);
        return ;
    }
    string tmp="";
    for(int j=i;j<s.length();++j){
        tmp.push_back(s[j]);
        if(hset.find(tmp)!=hset.end()){
            help(s,j+1,hset,(temp.empty()?tmp:temp + " " + tmp),res);
        }
    }
}
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>hset;
        for(int i=0;i<wordDict.size();++i)
            hset.insert(wordDict[i]);
        vector<string>res;
        string temp="";    
         help(s,0,hset,temp,res);
         return res;
    }
};