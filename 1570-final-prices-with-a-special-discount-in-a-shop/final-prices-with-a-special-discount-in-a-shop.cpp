class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>res(prices.size());
        for(int i=0;i<prices.size();++i){
            res[i]=prices[i];
            for(int j=i+1;j<prices.size();++j){
                if(prices[i]>=prices[j]){
                    res[i]-=prices[j];
                    break;
                }
            }
        }
        return res;
    }
};