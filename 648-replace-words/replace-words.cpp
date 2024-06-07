class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string>st;
        for(int i=0;i<dictionary.size();++i){
            st.insert(dictionary[i]);
        }
        string temp="";
        string res="";
        int i=0;
        while(i<sentence.size()){
            if(sentence[i]==' ') {
                if(temp!="") res+=temp;
                res.push_back(' ');
                temp="";
                i++;
            }
            else{
                temp.push_back(sentence[i++]);
                if(st.find(temp)!=st.end()){
                    while(i<sentence.size()&&sentence[i]!=' ')
                        i++;
                    res+=temp;
                    temp="";
                }
            }
        }
        if(temp!="") res+=temp;
        return res;
    }
};