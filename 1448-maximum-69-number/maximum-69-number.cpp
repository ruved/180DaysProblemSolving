class Solution {
public:
    int maximum69Number (int num) {
        int l=0,h=0;
        string ans=to_string(num);
        for(int i=0;i<ans.length();++i)
        {
            if(ans[i]=='6')
            { 
                ans[i]='9';
                break;
            }
        }
        return stoi(ans);
    }
};