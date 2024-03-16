class Solution {
public:
int mod=1e9+7;
int power(long long x, unsigned int y, int p){
        int res = 1; 
        x = x % p; 
        if (x == 0) return 0; 
        while (y > 0){
             if (y & 1)
                res = (res*x) % p;
            y = y>>1;
            x = (x*x) % p;
        }
        
        return res;
    }
    long long help(vector<int>& nums, int i,int k,int cnt,vector<vector<vector<int>>>&dp)
    {
        if(k==0&&i<0)
        {
            long ans=power(2,nums.size()-cnt,mod);
            return ans;
        }
        if(i<0) return 0;
        if(dp[i][k][cnt]!=-1) return dp[i][k][cnt];
        long long take=0,dont=0;
        if(k>=nums[i])
            take=help(nums,i-1,k-nums[i],cnt+1,dp);
        dont=help(nums,i-1,k,cnt,dp);
        return dp[i][k][cnt]=(take%mod+dont%mod)%mod;
            
    }
    int sumOfPower(vector<int>& nums, int k) {
        vector<vector<vector<int>>>dp(nums.size()+1,vector<vector<int>>(k+1,vector<int>(101,-1)));
       return  help(nums,nums.size()-1,k,0,dp);
    }
};