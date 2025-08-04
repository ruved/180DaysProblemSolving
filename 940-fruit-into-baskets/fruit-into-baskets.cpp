class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int j=0;
        unordered_map<int,int>mp;
        int mx=0;
        int temp=0;
        for(int i=0;i<fruits.size();++i){
            mp[fruits[i]]++;
           
            while((j<i)&&(mp.size()>2)){
                    mp[fruits[j]]--;
                    if(mp[fruits[j]]==0) mp.erase(fruits[j]);
                    j++;
            }
            mx=max(mx,i-j+1);
        }
        return mx;
    }
};