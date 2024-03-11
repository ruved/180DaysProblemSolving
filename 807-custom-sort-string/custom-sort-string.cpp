class Solution {
public:
    string customSortString(string order, string s) {
      unordered_map<char,int>mp;
        for(int i=0;i<order.length();++i)
            mp[order[i]]=i;
        vector<pair<int,char>>temp;
        string ans="";
        for(int i=0;i<s.length();++i)
        {
            if(mp.find(s[i])!=mp.end())
             temp.push_back({mp[s[i]],s[i]});
            else
                ans.push_back(s[i]);
        }
        sort(temp.begin(),temp.end());
        for(int i=0;i<temp.size();++i)
            ans.push_back(temp[i].second);
       return ans;
         
    }
};