class Solution {
public:

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size() , ans = 1;
        vector<pair<int,double>> cars(n);
        //positions of cars and the time taken to reach target. 
        for(int i=0;i<n;i++){
            cars[i].first = position[i];
            cars[i].second = (double)(target - position[i])/(double)(speed[i]);
        }
        sort(cars.begin() , cars.end());
        for(int i=0;i<n;i++){
            cout<<cars[i].first<<" "<<cars[i].second<<"\n";
        }
        double slowest = cars[n-1].second;        

        for(int i=n-2;i>=0;i--){
            if(cars[i].second > slowest) {
                ans++; 
                slowest = cars[i].second;
            }
        }
        return ans;
    }
};