class Solution {
public:
    string lexSmallest(string s) {
        int n=s.size();
        string ans=s;
        for(int k=0;k<n;k++){
            string c=s;
            reverse(c.begin(),c.begin()+k+1);
            ans=min(ans,c);
            c=s;
            reverse(c.begin()+k+1,c.end());
            ans=min(ans,c);
        }
        return ans;
    }
};