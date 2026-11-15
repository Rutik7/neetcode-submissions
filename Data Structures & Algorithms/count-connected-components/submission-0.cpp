class Solution {
public:
    int BFS(queue<int>& q, vector<vector<int>>& adj,vector<bool>& visited)
    {
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            visited[u] = true;

            for(int v: adj[u])
            {
                if(!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        return 1;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        //step 1: build the adjency list
        vector<vector<int>> adj(n);
        int ans = 0;
        for(const auto& edge: edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // step 2: BFS traversal
        // for that I need the queue and visited array

        vector<bool> visited(n,false);
        queue<int> q;

        for(int i = 0;i<n;i++)
        {
            if(!visited[i])
            {
                q.push(i);
                ans += BFS(q,adj,visited);
            }
        }

        return ans;
        
    }
};
