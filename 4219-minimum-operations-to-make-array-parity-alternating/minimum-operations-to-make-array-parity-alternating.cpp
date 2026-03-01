class Solution {
public:
    vector<int> countparity(vector<int> temp,bool startParity){
        vector<int>nums=temp;
        int n = nums.size();
    int expected = startParity;
    

    int m = *min_element(nums.begin(), nums.end());
    int M = *max_element(nums.begin(), nums.end());

    int ops = 0;

    for(int i = 0; i < n; i++) {
        if((nums[i] & 1) != expected) {
            ops++;

            if(nums[i] == m)
                nums[i] += 1;
            else if(nums[i] == M)
                nums[i] -= 1;
            else
                nums[i] += 1; // arbitrary
        }
        expected ^= 1;
    }
    int newMin = *min_element(nums.begin(), nums.end());
    int newMax = *max_element(nums.begin(), nums.end());

    vector<int>a= {ops, newMax - newMin};
     ops = 0;
     expected = startParity;
     nums=temp;
    for(int i = 0; i < n; i++) {
        if((nums[i] & 1) != expected) {
            ops++;

            if(nums[i] == m)
                nums[i] += 1;
            else if(nums[i] == M)
                nums[i] -= 1;
            else
                nums[i] -= 1; // arbitrary
        }
        expected ^= 1;
    }

     newMin = *min_element(nums.begin(), nums.end());
     newMax = *max_element(nums.begin(), nums.end());

    vector<int>b= {ops, newMax - newMin};
    return {ops,min(a[1],b[1])};
    }
    
    vector<int> makeParityAlternating(vector<int>& nums) {
        // int a=countparity(nums,0);
        // int b=countparity(nums,1);
        // int minele=*min_element(nums.begin(),nums.end());
        // int maxele=*max_element(nums.begin(),nums.end());
        vector<int> a=countparity(nums,0);
        vector<int> b=countparity(nums,1);
        if(a[0]<b[0]) return a;
        else if(a[0]>b[0]) return b;
        else{
            return a[1]<b[1]?a:b;
        }
    }
};