class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>mp;
        for(int i=0;i<arr1.size();++i){
            mp[arr1[i]]++;
        }
        vector<int>res;
        for(int i=0;i<arr2.size();++i){
            if(mp.find(arr2[i])!=mp.end()){
                int x=mp[arr2[i]];
                while(x--){
                    res.push_back(arr2[i]);
                }
                mp.erase(arr2[i]);
            }
        }
        for(auto it:mp){
            int x=it.second;
            while(x--) res.push_back(it.first);
        }
        return res;
    }
};