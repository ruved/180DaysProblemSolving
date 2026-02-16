class Solution {
public:
bool checkpal(string s){
    int i=0,j=s.length()-1;
    while(i<j){
        if(s[i]!=s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
void help(string &s,int i,vector<string>temp,vector<vector<string>>&res){
    if(i>=s.length()){
        res.push_back(temp);
        return ;
    }
    string temp2="";
    for(int j=i;j<s.length();++j){
        temp2+=s[j];
        if(checkpal(temp2)){
            temp.push_back(temp2);
            help(s,j+1,temp,res);
            temp.pop_back();
        }
            
    }
}
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        vector<vector<string>>res;
        help(s,0,temp,res);
        return res;
    }
};