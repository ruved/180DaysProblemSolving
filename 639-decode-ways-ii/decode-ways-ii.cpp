class Solution {
public:
    
    int MOD = 1e9 + 7;
    
    int f(int i, string &s, vector<int> &dp)
        {
            if(i >= s.size())
                return 1;
        
            else if(s[i] == '0')
                return 0;
        
            if(dp[i] != -1)
                return dp[i];
       
            long long oneCharChoice = f(i + 1, s, dp);
            if(s[i] == '*')
                oneCharChoice = (9 * oneCharChoice) % MOD;
        
            long long twoCharChoice1 = 0;
            long long twoCharChoice2 = 0;
        
            if(i + 1 < s.size())
            {
                if(s[i] == '1' || s[i] == '*')
                {
                    twoCharChoice1 = f(i + 2, s, dp);
                    
                    if(s[i + 1] == '*')
                        twoCharChoice1 = (9 * twoCharChoice1) % MOD;
                }
                if(s[i] == '2' || s[i] == '*')
                {
                    if (s[i + 1] == '*')
                    {
                        twoCharChoice2 = f(i + 2, s, dp);
                        twoCharChoice2 = (6 * twoCharChoice2) % MOD;
                    }
                    else if (s[i + 1] - '0' <= 6)
                    {
                            twoCharChoice2 = f(i + 2, s, dp);
                    }
                }
            }
            
            return dp[i] = ((oneCharChoice + twoCharChoice1)%MOD + twoCharChoice2) % MOD;
        }

        int numDecodings(string s) {
            
            int n = s.size();
            vector<int> dp(n + 1, -1);
            return f(0, s, dp);
        }
};