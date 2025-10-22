class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        //minimum sum of n-k window
        int n=cardPoints.size();
        int sum=0;
        int total=0;
        for(int i=0;i<n-k;++i){
            sum+=cardPoints[i];
        }
        total=sum;
        int res=sum;
        for(int i=1;i<=k;++i){
            sum=sum-cardPoints[i-1]+cardPoints[i+n-k-1];
            res=min(sum,res);
            total+=cardPoints[i+n-k-1];
        }
        return total-res;
    }
};