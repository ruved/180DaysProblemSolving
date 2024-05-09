class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n=happiness.size()-1;
        sort(happiness.begin(),happiness.end());
        long long ans=0;
        for(int i=0;i<k;++i){
            ans+=(happiness[n-i]-i)<0?0:(happiness[n-i]-i);
        }
        return ans;
    }
};