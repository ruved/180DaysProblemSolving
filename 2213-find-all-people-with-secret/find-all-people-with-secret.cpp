class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map<int,vector<pair<int,int>>>time_Meeting;
        for(int i=0;i<meetings.size();++i)
        {
            time_Meeting[meetings[i][2]].push_back({meetings[i][0],meetings[i][1]});
        }
        vector<bool>knowSecret(n,false);
        knowSecret[0]=true;
        knowSecret[firstPerson]=true;
        for(auto it:time_Meeting)
        {
            vector<pair<int,int>>temp=it.second;
            unordered_map<int,vector<int>>adj;
            unordered_set<int>alreadyAdded;
            queue<int>que;
            for(auto &[person1,person2]:temp)
            {
                adj[person1].push_back(person2);
                adj[person2].push_back(person1);
                if(knowSecret[person1]==true&&alreadyAdded.find(person1)==alreadyAdded.end())
                {
                    que.push(person1);
                    alreadyAdded.insert(person1);
                }
                if(knowSecret[person2]==true&&alreadyAdded.find(person2)==alreadyAdded.end())
                {
                    que.push(person2);
                    alreadyAdded.insert(person2);
                }
            }
            
            while(!que.empty())
            {
                int person=que.front();
                que.pop();
                for(int &nextPerson:adj[person])
                {
                    if(!knowSecret[nextPerson])
                    {
                        knowSecret[nextPerson]=true;
                        que.push(nextPerson);
                    }
                }
            }
            
        }
        vector<int>res;
        for(int i=0;i<n;++i)
        {
            if(knowSecret[i])
                res.push_back(i);
        }
        return res;
    }
};