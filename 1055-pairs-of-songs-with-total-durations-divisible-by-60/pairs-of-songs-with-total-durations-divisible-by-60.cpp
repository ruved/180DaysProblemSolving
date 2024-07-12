class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count=0;
        unordered_map<int,int>mp;
        for(int i=0;i<time.size();++i){
            if(mp.find(60-time[i]%60)!=mp.end())
                count+=mp[60-time[i]%60];
            mp[time[i]%60]++;
        }
        long long ans=mp[0];
        ans=ans*(ans-1)/2;

        return count+ans;
    }
};