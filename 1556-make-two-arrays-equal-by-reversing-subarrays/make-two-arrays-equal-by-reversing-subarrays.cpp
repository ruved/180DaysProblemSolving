class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        
        if(target.size()!=arr.size()) return false;
        
        unordered_map<int,int>mp;
        for(int i=0;i<target.size();++i)
            mp[target[i]]++;

        for(int i=0;i<arr.size();++i){
            if(mp.find(arr[i])==mp.end()) return false;

            mp[arr[i]]--;
            if(mp[arr[i]]==0)
            mp.erase(arr[i]);
        }
        return mp.size()==0;
    }
};