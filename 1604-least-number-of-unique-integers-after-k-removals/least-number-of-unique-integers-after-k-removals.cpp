class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();++i)
            mp[arr[i]]++;
        
        int unique=mp.size();
        vector<pair<int,int>>ar;
        for(auto it:mp)
        {
            ar.push_back({it.second,it.first});
        }
        sort(ar.begin(),ar.end());
        int i=0;
        while(k>0)
        {
            // cout<<ar[i].first<<" "<<ar[i].second<<"::";
            if(k>=ar[i].first)
                k-=ar[i].first;
            else
                break;
            i++;
        }
        return ar.size()-i; 
    }
};