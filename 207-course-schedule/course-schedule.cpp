class Solution {
public:
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        vector<int> adj[numCourses];
        
		for (auto it : prerequisites) 
			adj[it[1]].push_back(it[0]);
		
        for(int i=0;i<prerequisites.size();++i)
            indegree[prerequisites[i][0]]++;
        
        queue<int>q;
        for(int i=0;i<numCourses;++i)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        vector<int> topo;
        while(!q.empty())
        {
           int t=q.front();
            q.pop();
            topo.push_back(t);
            for(int v:adj[t])
            {
                indegree[v]--;
                if(indegree[v]==0)
                    q.push(v);
            }
        }
        
        if (topo.size() == numCourses) return true;
		return false;
    }
};
// 0->1