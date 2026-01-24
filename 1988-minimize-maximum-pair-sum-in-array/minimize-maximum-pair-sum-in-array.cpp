class Solution {
public:
    int minPairSum(vector<int>& nums) {
        //To minimize, we can sort first
        sort(nums.begin(), nums.end());
        int max_min_sum = nums[0] + nums[nums.size()-1];
        int cur_sum = 0;

        //minimum sums can be chosen by choosing the numbers at either ends of the sorted array
        //Then, maximize those sums.
        for(int i = 1; i < nums.size() / 2; i++){
            cur_sum = nums[i] + nums[nums.size() - i - 1];
            max_min_sum = max(max_min_sum, cur_sum);
        }
        return max_min_sum;
    }
};