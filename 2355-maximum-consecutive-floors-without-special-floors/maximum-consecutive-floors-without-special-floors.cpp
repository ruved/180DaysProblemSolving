class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        int prev=special[0];
        int ans=0;
        int n=special.size();
        for(int i=1;i<n;++i){
            ans=max(ans,special[i]-prev);
            prev=special[i];
        }
        ans=max(ans-1,max(top-prev,special[0]-bottom));
        return ans;
    }
};