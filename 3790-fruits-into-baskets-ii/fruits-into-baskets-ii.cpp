class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        vector<bool>flag(baskets.size(),false);
        int j=0;
        bool b=false;
        int ans=0;
        for(int i=0;i<fruits.size();++i){
            b=false;
            for(int j=0;j<baskets.size();++j){
                if(!flag[j]&&(fruits[i]<=baskets[j])){
                    flag[j]=true;
                    b=true;
                    break;
                }
            }
            if(!b) ans++;
        }
        return ans;
    }
};