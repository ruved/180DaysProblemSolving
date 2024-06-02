class Solution {
public:
    string clearStars(string s) {
        map<char,set<int>>pq;
        for(int i=0;i<s.length();++i){
            if(s[i]=='*'){
               auto it=pq.begin();
               it->second.erase(prev(it->second.end()));
               if(it->second.size()==0)
                pq.erase(it);
            }else{
                set<int>st;
                if(pq.find(s[i])==pq.end())
                pq.insert({s[i],st});
            pq[s[i]].insert(i);
            }
        }
        string ans="";
        for(int i=0;i<s.length();++i){
    if(pq.find(s[i])!=pq.end()&&pq[s[i]].find(i)!=pq[s[i]].end())
                ans+=s[i];
        }
        return ans;
    }
};