class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // Determine the graph size
        int n = edges.size();

        // build the two way adjencency list and build the degree array
        vector<vector<int>> adj(n+1);
        vector<int> degree(n+1,0);
        for(const auto& edge: edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            degree[u]++;
            adj[v].push_back(u);
            degree[v]++;
        }

        //feed the queue whose degree == 1
        queue<int> q;
        for(int i = 1;i<=n;i++)
        {
            if(degree[i]==1)
            {
                q.push(i);
            }
        }

        // trim the leaves node
        while(!q.empty())
        {
            int u = q.front();
            q.pop();

            for(int v: adj[u])
            {
                degree[v]--;
                if(degree[v] == 1)
                {
                    q.push(v);
                }
            }
        }

        // scan the edges backwords from index n-1 down to 0
        for(int i = n-1 ; i>= 0 ;i--)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            if(degree[u] > 1 && degree[v]>1)
            {
                return edges[i];
            }
        }

        return {};
    }
};