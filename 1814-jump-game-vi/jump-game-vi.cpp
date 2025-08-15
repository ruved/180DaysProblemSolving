class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int> q{0};
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (q.front() < i - k) q.pop_front();
            nums[i] += nums[q.front()];
            int num = nums[i];
            while (!q.empty() && nums[q.back()] <= num) q.pop_back();
            q.push_back(i);
        }
        return nums.back();
    }
};