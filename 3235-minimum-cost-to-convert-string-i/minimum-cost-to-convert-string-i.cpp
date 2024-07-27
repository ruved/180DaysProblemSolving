class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long arr[26][26];
        for (int i = 0; i < 26; i++) {
            fill(arr[i], arr[i] + 26, LLONG_MAX); 
            arr[i][i] = 0; 
        }
        
        // Fill the transformation costs
        for (int i = 0; i < original.size(); i++) {
            int val1 = original[i] - 'a';
            int val2 = changed[i] - 'a';
            arr[val1][val2] = min(arr[val1][val2], (long long)cost[i]); 
        }
        

        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (arr[i][k] != LLONG_MAX && arr[k][j] != LLONG_MAX) {
                        arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
                    }
                }
            }
        }
        
        long long ans = 0; 
        for (int i = 0; i < source.size(); i++) {
            int val1 = source[i] - 'a';
            int val2 = target[i] - 'a';

            if (val1 == val2) {
                continue; 
            }

            if (arr[val1][val2] == LLONG_MAX) {
                return -1; 
            } else {
        
                if (ans > LLONG_MAX - arr[val1][val2]) {
                    return -1; 
                }
                ans += arr[val1][val2]; 
            }
        }
        return ans; 
    }
};