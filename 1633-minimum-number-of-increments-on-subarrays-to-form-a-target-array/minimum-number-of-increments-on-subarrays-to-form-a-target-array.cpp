class Solution {
public:
    int minNumberOperations(vector<int>& a) {
        int n = a.size();
        
        vector<int> diff = a;
        for(int i = 1; i < n; i++)
            diff[i] = a[i] - a[i - 1];
        
        int cnt = 0;
        for(auto ele : diff)
            if(ele > 0)
                cnt += ele;
        
        return cnt;
        
    }
};