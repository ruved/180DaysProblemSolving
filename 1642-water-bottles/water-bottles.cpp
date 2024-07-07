class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=0;
        while(numBottles){
            int extra=numBottles/numExchange;
            ans+=extra*numExchange;
            numBottles=numBottles%numExchange;
            numBottles+=extra;
            if(numBottles<numExchange){
                ans+=numBottles;
                numBottles=0;
                break;
            }
        }
        return ans;
    }
};