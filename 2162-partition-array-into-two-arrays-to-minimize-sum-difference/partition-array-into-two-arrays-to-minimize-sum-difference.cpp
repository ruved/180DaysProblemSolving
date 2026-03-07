class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        int total = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> left(n+1), right(n+1);

        // enumerate subsets of first half
        for(int mask = 0; mask < (1<<n); mask++){
            int sum = 0, cnt = 0;

            for(int i = 0; i < n; i++){
                if(mask & (1<<i)){
                    sum += nums[i];
                    cnt++;
                }
            }

            left[cnt].push_back(sum);
        }

        // enumerate subsets of second half
        for(int mask = 0; mask < (1<<n); mask++){
            int sum = 0, cnt = 0;

            for(int i = 0; i < n; i++){
                if(mask & (1<<i)){
                    sum += nums[i+n];
                    cnt++;
                }
            }

            right[cnt].push_back(sum);
        }

        // sort right side for binary search
        for(int i = 0; i <= n; i++)
            sort(right[i].begin(), right[i].end());

        int ans = INT_MAX;

        // merge step
        for(int k = 0; k <= n; k++){

            for(int s1 : left[k]){

                int target = total/2 - s1;

                auto &vec = right[n-k];

                auto it = lower_bound(vec.begin(), vec.end(), target);

                if(it != vec.end()){
                    int S = s1 + *it;
                    ans = min(ans, abs(total - 2*S));
                }

                if(it != vec.begin()){
                    --it;
                    int S = s1 + *it;
                    ans = min(ans, abs(total - 2*S));
                }
            }
        }

        return ans;
    }
};