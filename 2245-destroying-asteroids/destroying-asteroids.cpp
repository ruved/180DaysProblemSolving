class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long int ans=mass;
        for(int i=0;i<asteroids.size();++i){
            if(ans<asteroids[i])
            return false;
            ans+=asteroids[i];
        }
        return true;
    }
};