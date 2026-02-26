class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        
        int prefixSum = 0;
        int total = 0;
        
        for (int i = satisfaction.size() - 1; i >= 0; i--) {
            prefixSum += satisfaction[i];
            
            if (prefixSum > 0) {
                total += prefixSum;
            } else {
                break;
            }
        }
        
        return total;
    }
};