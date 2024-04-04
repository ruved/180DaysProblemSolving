class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int ans=0;
        for(int i=0;i<s.length();++i)
        {
            if(s[i]=='(')
            {
                st.push('(');
                ans=ans<st.size()?st.size():ans;
            }
            else if(s[i]==')')
            {
            
                st.pop();
            }
        }
        return ans;
    }
};