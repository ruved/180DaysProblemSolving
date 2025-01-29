class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=0;
        int n=prices.size();
        int i=0;
        int dif=0;
        while(i<n){
            if(prices[buy]>prices[i]){
                buy=i;
            }else{
                int temp=prices[i]-prices[buy];
                dif=max(temp,dif);
            }
            i++;
        }
        return dif;
    }
};

// 7 5 3 6 4 1