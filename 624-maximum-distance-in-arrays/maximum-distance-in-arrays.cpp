class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        pair<int,int> firstmin={INT_MAX,-1},secondmin={INT_MAX,-1};
        pair<int,int>  firstmax={INT_MIN,-1},secondmax={INT_MIN,-1};
        for(int i=0;i<arrays.size();++i){

            if(firstmin.first>=arrays[i][0]){
                secondmin=firstmin;
                firstmin={arrays[i][0],i};
            }else if(secondmin.first>=arrays[i][0])
                secondmin={arrays[i][0],i};

            if(firstmax.first<=arrays[i][arrays[i].size()-1]){
                secondmax=firstmax;
                firstmax={arrays[i][arrays[i].size()-1],i};
            }else if(secondmax.first<=arrays[i][arrays[i].size()-1])
                secondmax={arrays[i][arrays[i].size()-1],i};
        }
        if(firstmax.second!=firstmin.second) 
            return abs(firstmax.first-firstmin.first);

        if(secondmin.first!=INT_MAX) 
        return max(abs(firstmin.first-secondmax.first),abs(firstmax.first-secondmin.first));
            return 0;
 
    }
};