class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // step 1: edge count check
        if (edges.size() != n - 1) return false;

        // step 2: Build 2 way adjacency list
        vector<vector<int>> adj(n);
        for(const auto& edge: edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // step 3: Run BFS from Node 0
        vector<bool> visited(n,false);
        queue<int> q;

        // seed the queue with node 0, and mark 0 as visited and start a counter at 0;
        q.push(0);
        visited[0] = true;
        int counter = 0;

        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            counter++;

            for(int v : adj[u])
            {
                if(!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }


        // final check 
        return counter == n;


    }
};
