class Solution {
public:

    string answerString(string word, int numFriends) {
        if(numFriends==1) return word;
        char c=-1;
        vector<int>pos;
        for(int i=0;i<word.size();++i){
            if(c<=(word[i]-'a')){
                c=word[i]-'a';
                if(c<(word[i]-'a')) pos.clear();
                pos.push_back(i);
            }
        }
        int len=word.size()-numFriends+1;
        string s="";
        for(int i=0;i<pos.size();++i){
            string sub;
            if((pos[i]+len)<word.size())
                sub=word.substr(pos[i],len);
            else 
                sub=word.substr(pos[i]);
            if(s<sub) s=sub;
        }
        return s;
    }
};