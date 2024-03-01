class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0) return 0;
        unordered_set<char>unorderd_st;
        int start=0,end=0;
        int j=0;
        int ans=0;
        for(int i=0;i<s.length();++i)
        {
            if(unorderd_st.find(s[i])==unorderd_st.end())
            { 
                end=i;
            }
            else
            {
                ans=max(ans,end-start+1);
                while(unorderd_st.find(s[i])!=unorderd_st.end())
                {
                    unorderd_st.erase(s[j]);
                    j++;
                }
                
                start=j;
            }
            unorderd_st.insert(s[i]);
        }
        ans=max(ans,end-start+1);
        return ans;
    }
};