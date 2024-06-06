class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int>mp;
        for(int i=0;i<hand.size();++i)
            mp[hand[i]]++;

        while(mp.size()>0){
            auto it=mp.begin();
            int nums=it->first;
            for(int k=0;k<groupSize;++k){
                if(mp.find(nums)==mp.end())return false;
                mp[nums]--;
                if(mp[nums]==0) mp.erase(nums);
                nums++;
            }

        }

        return true;

    }
};