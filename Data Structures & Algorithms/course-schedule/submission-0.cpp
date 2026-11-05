class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 1. Initialize an in-degree vector of size numCourses with 0
        // adj list
        vector<vector<int>> adj(numCourses);

        vector<int> inDegree(numCourses,0);
        // iterate through each edge/prerequisite pair
        for(const auto& pre: prerequisites)
        {
            int course = pre[0];
            int prereq = pre[1];

            inDegree[course]++;
            adj[prereq].push_back(course); // prereq -> course
        }

        // now add all nodes with in-degree==0 to a queue

        queue<int> q;
        for(int i = 0;i<numCourses;i++)
        {
            if(inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        // Now BFS
        int processedCourses = 0;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            processedCourses++;

            for(int v: adj[u])
            {
                inDegree[v]--;
                if(inDegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }


        // now return 
        return processedCourses == numCourses;

    }
};