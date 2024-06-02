class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int ans = INT_MAX; 
        for(int i=0; i<nums.size(); i++){
            int x = nums[i]; 
            ans = min(ans, abs(x-k)); 

            for(int j=i; j<nums.size() && j<i+35; j++){ 
                x = (x&nums[j]); 
                ans = min(ans, abs(x - k)); 
            }
        }
        
        return ans; 
    }
};