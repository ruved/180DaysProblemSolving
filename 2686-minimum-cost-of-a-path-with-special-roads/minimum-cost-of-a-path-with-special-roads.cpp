class Solution {
public:
    int getCost(int x1,int y1, int x2, int y2){
        return abs(x2-x1) + abs(y2-y1);
    }

    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        map<pair<int,int>,vector<vector<int>>> graph;
    
        for(int j = 0; j < specialRoads.size(); j++)
            graph[{specialRoads[j][0],specialRoads[j][1]}].push_back({specialRoads[j][2],specialRoads[j][3],specialRoads[j][4]});

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        pq.push({0,{start[0],start[1]}});
        int ans = INT_MAX;

        map<pair<int,int>,int> visited;

        while(!pq.empty()){
            pair<int,int> curr = pq.top().second;
            int cost = pq.top().first;
            pq.pop();
            
            if(visited.find({curr.first,curr.second}) != visited.end()) continue;
            visited[{curr.first,curr.second}] = 1;

            if(curr.first == target[0] && curr.second == target[1])     
                return cost;
                
            pq.push({cost +  getCost(target[0],target[1],curr.first,curr.second),{target[0],target[1]}});
            for(auto &i : specialRoads)
                pq.push({cost +  getCost(i[0],i[1],curr.first,curr.second),{i[0],i[1]}});
            for(auto &i : graph[{curr.first,curr.second}])
                pq.push({cost + i[2],{i[0],i[1]}});
        }

        return ans;
    }
};