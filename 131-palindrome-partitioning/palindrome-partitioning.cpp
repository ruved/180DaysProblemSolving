class Solution {
public:
bool checkpal(string s){
    int i=0,j=s.length()-1;
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
void help(string s,int i,vector<vector<string>>&ans,vector<string>&temp){
    if(i==s.length()) {
        if(temp.size()>0)
        ans.push_back(temp);
        return ;
    }
    for(int j=i;j<s.length();++j){
        string sub=s.substr(i,j-i+1);
        if(checkpal(sub)){
            temp.push_back(sub);
            help(s,j+1,ans,temp);
            temp.pop_back();
        }
    }

}
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        help(s,0,ans,temp);
        return ans;
    }
};