class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
      int ans=INT_MIN;
      int len=energy.size()-1;
      int j=len;

        while(len>j-k)
        {
            int i=len;
            int temp=0;
            while(i>=0)
            {
                temp+=energy[i];
                ans=max(ans,temp);
                i-=k;
            }
            len--;
        }
        return ans;
    }
};