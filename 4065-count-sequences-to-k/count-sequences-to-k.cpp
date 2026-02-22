class Solution {
public:
    unordered_map<int,vector<int>>mp;
    map<tuple<int,int,int,int>, int> dp;
    int help(vector<int>& nums, vector<int>pfreq,int i){
        if(i<0) 
            return (pfreq[0]==0&&pfreq[1]==0&&pfreq[2]==0);
        auto key = make_tuple(i, pfreq[0], pfreq[1], pfreq[2]);
        if(dp.count(key)) return dp[key];
        int take=(nums[i]==1)?2*help(nums,pfreq,i-1):0;
        vector<int>temp=mp[nums[i]];
        if(nums[i]>1){
            pfreq[0]+=temp[0];
            pfreq[1]+=temp[1];
            pfreq[2]+=temp[2];
            take+=help(nums,pfreq,i-1);
            pfreq[0]-=temp[0];
            pfreq[1]-=temp[1];
            pfreq[2]-=temp[2];
        }
        if(nums[i]>1){
            pfreq[0]-=temp[0];
            pfreq[1]-=temp[1];
            pfreq[2]-=temp[2];
                take+=help(nums,pfreq,i-1);
            pfreq[0]+=temp[0];
            pfreq[1]+=temp[1];
            pfreq[2]+=temp[2];
        }
        int notake=help(nums,pfreq,i-1);
        return dp[key]=take+notake;
        
    }
    int countSequences(vector<int>& nums, long long k) {
        vector<int>pfreq(3,0);
        // long long ans=k;
        int ans=0;
        // if(k==1) ans++;
        while(k>1){
            if(k%2==0) {pfreq[0]++;k/=2;}
            else if(k%3==0) {pfreq[1]++;k/=3;}
            else if(k%5==0) {pfreq[2]++;k/=5;}
            else return 0;
            // cout<<pfreq[0]<<" "<<pfreq[1]<<" "<<pfreq[2]<<" - ";
        }
        mp[1]={0,0,0};
        mp[2]={1,0,0};
        mp[3]={0,1,0};
        mp[4]={2,0,0};
        mp[5]={0,0,1};
        mp[6]={1,1,0};
        // cout<<"HI "<<pfreq[0]<<" "<<pfreq[1]<<" "<<pfreq[2]<<" - ";
        
        ans+= help(nums,pfreq,nums.size()-1);
         return ans;
    }
};