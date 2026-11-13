class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;
        //step 1 Build indegree array and adjecency list
        vector<int>indegree(numCourses,0);
        vector<vector<int>> adj(numCourses);

        for(const auto& courses : prerequisites)
        {
            int course = courses[0]; // destination ( incomming arrow )
            int preq = courses[1];  // source (outgoing arrow)
            indegree[course]++;

            //for the adjency list 
            adj[preq].push_back(course);

        }

        // step 2 feed the queue whose indegerr is 0
        queue<int>q;
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

        // step 3 BFS
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            result.push_back(u); // record of the course is complete indegree is 0

            for(auto v:adj[u])
            {
                indegree[v]--;
                if(indegree[v] == 0)
                {
                    q.push(v);
                }
                    
            }
        }

        // need to check cycle if yes then return empty array
        if(result.size() == numCourses)
        {
            return result;
        }
        else
        return {};
    }
};
