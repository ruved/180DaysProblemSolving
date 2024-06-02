class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int ans = INT_MAX; 
        for(int i=0; i<nums.size(); i++){
            int x = nums[i]; // Get the current element
            ans = min(ans, abs(x-k)); // Update the answer with the minimum difference between the current element and k

            for(int j=i; j<nums.size() && j<i+35; j++){ // Iterate through the next 35 elements or until the end of the array
                x = (x&nums[j]); // Update x by performing bitwise AND with the next element
                ans = min(ans, abs(x - k)); // Update the answer with the minimum difference between the updated x and k
            }
        }
        
        return ans; // Return the final answer
    }
};