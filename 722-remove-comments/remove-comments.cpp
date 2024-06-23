class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string>ans;
        bool block = false;
        string current;

        for(auto s:source)
        {
            int i = 0;
            if(!block)current.clear();

            while(i<s.length())
            {
                if(!block and i+1 <s.length() and s[i] =='/' and s[i+1] =='*') 
                {
                    block = true; i++;
                }

                else if(block and i+1 < s.length() and s[i] =='*' and s[i+1]=='/') 
                {
                    block = false; i++;
                }

                else if(!block and i+1 < s.length() and s[i]=='/' and s[i+1]=='/') break;

                else if(!block) current += s[i];
                i++;
            }

            if(!block and !current.empty()) ans.push_back(current);
        }
        return ans;
    }
};