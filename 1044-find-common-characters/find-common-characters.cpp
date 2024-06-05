class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
       vector<int>freq(26,0);
       for(int i=0;i<words[0].size();++i)
            freq[words[0][i]-'a']++;
       

       for(int i=1;i<words.size();++i){
            vector<int>freq1(26,0);
            for(int j=0;j<words[i].size();++j)
                freq1[words[i][j]-'a']++;
            
            for(int j=0;j<26;++j)
                freq[j]=min(freq[j],freq1[j]);
            
       }
       vector<string>ans;
       for(int j=0;j<26;++j){
        int x=freq[j];
            while(x) {
                string c(1,j+'a');
                ans.push_back(c);
                x--;
            }
       }
       return ans;
    }
};