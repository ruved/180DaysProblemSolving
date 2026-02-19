class Solution {
public:
bool help(string &word,int i,unordered_set<string>&hset,vector<int>&dp){
    if(i==word.length()) return true;
    if(dp[i]!=-1) return dp[i];
    bool ans=false;
    string tmp="";
    for(int j=i;j<word.length();++j){
            tmp.push_back(word[j]);
            if((hset.find(tmp)!=hset.end())&&help(word,j+1,hset,dp))
                return true;
    }
    return dp[i]=ans;
}
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string>hset;
        sort(words.begin(),words.end(),[](auto a,auto b){
            return a.length()<b.length();
        });
        vector<string>ans;
        
        // for(int i=0;i<words.size();++i){
        //     vector<int>dp(words[i].length(),-1);
        //     if(!hset.empty()&&help(words[i],0,hset,dp)) ans.push_back(words[i]);
        //     hset.insert(words[i]);
        // }
        hset.insert(words[0]);
        for (int i = 1; i < words.size(); ++i) {
            int n = words[i].length();
            if (n == 0) continue;

            vector<bool> dp(n + 1, false);
            dp[n] = true;

            for (int k = n - 1; k >= 0; --k) {
                string tmp = "";

                for (int j = k; j < n; ++j) {
                    tmp.push_back(words[i][j]);

                    if (hset.count(tmp) && dp[j + 1]) {
                        dp[k] = true;
                        break;
                    }
                }
            }

            if (dp[0])
                ans.push_back(words[i]);

            hset.insert(words[i]);
        }
        return ans;
    }
};