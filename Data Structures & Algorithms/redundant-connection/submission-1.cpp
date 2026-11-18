class Solution {
public:

    int find(int x, vector<int>& parent)
    {
        // base condition 
        if(parent[x] == x) return x;

        // recursive step
        return parent[x] = find(parent[x],parent);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        // create a parent array of size n+1 where every starts as its own leader
        vector<int> parent(n+1);

        for(int i = 1 ;i<=n ; i++)
        {
            parent[i] = i; // node itself is it's own leader
        }

        for(const auto& edge: edges)
        {
            int bossV = find(edge[0],parent);
            int bossU = find(edge[1],parent);

            if(bossU == bossV) 
                return edge;

            else
            {
                parent[bossU] = bossV;
            }
        }

        return {};

        
    }
};