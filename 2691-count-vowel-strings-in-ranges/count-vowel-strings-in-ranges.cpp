class Solution {
public:
bool checkvowel(string s){
    int n=s.length()-1;
    return (s[0]=='a'||s[0]=='e'||s[0]=='i'||s[0]=='o'||s[0]=='u')&&
    (s[n]=='a'||s[n]=='e'||s[n]=='i'||s[n]=='o'||s[n]=='u');
}
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int>prefix(words.size(),0);
        prefix[0]=checkvowel(words[0]);

        for(int i=1;i<words.size();++i){
            prefix[i]+=prefix[i-1];
            if(checkvowel(words[i]))
                prefix[i]++;
        }

        vector<int>res(queries.size(),0);
        for(int i=0;i<queries.size();++i){
            int l=queries[i][0];
            int r=queries[i][1];
            cout<<r<<" ";
            res[i]+=prefix[r];
            res[i]-=(l>0)?prefix[l-1]:0;
        }
        return res;
    }
};

