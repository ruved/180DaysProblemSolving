class Solution {
public:
    string removeOccurrences(string s, string part) {
        int pos=s.find(part);
        int l=part.length();
        while(pos!=string::npos){
            s.erase(pos,l);
            pos=s.find(part);
        }
        return s;
    }
};