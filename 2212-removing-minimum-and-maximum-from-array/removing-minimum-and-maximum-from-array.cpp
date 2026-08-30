class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini=min_element(nums.begin(),nums.end())-nums.begin();
        int maxi=max_element(nums.begin(),nums.end())-nums.begin();
        int st=min(mini,maxi);
        int en=max(mini,maxi);
        int n=nums.size();
        int fromFront = en + 1;
        int fromBack = n - st;
        int bothSides = (st + 1) + (n - en);

        return min({fromFront, fromBack, bothSides});

    }
};