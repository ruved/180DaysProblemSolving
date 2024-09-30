class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    queue<int>q;
    vector<vector<int>>adj(numCourses);
    vector<int>input(numCourses,0);
    for(int i=0;i<prerequisites.size();++i){
        input[prerequisites[i][0]]++;
        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }
    for(int i=0;i<numCourses;++i)
        if(input[i]==0) q.push(i);
 vector<int>top;
    while(!q.empty()){
           int currnode=q.front();
           q.pop();
            top.push_back(currnode);
            for(int j=0;j<adj[currnode].size();++j){
                    input[adj[currnode][j]]--;
                    if(input[adj[currnode][j]]==0)
                        q.push(adj[currnode][j]);
            }
        }
        return top.size()==numCourses;
    }
};
