class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char>st;
        for(int i=0;i<allowed.length();++i)
            st.insert(allowed[i]);
        int count=0;
        bool f=true;
        for(int i=0;i<words.size();++i){
            f=true;
            for(int j=0;j<words[i].length();++j)
                if(st.find(words[i][j])==st.end()){
                    f=false;
                    break;
                }
            if(f) count++;
        }
        return count;
    }
};