class Solution {
public:
    void bfs(vector<vector<int>>& grid , queue<pair<int,int>>& q)
    {
        while(!q.empty())
        {
            pair<int,int> curr = q.front();
            q.pop();
            int r = curr.first;
            int c = curr.second;

            // up 
            if(r-1 >=0 && grid[r-1][c] == INT_MAX)
            {
                grid[r-1][c] = grid[r][c] + 1;
                //sink immediately on push
                q.push({r-1,c});
            }

            // down
            if(r+1 < grid.size() && grid[r+1][c] == INT_MAX)
            {
                grid[r+1][c] = grid[r][c] + 1;
                q.push({r+1,c});
            }

            // left
            if(c-1 >=0 && grid[r][c-1] == INT_MAX)
            {
                grid[r][c-1] = grid[r][c] + 1;
                q.push({r,c-1});
            }

            // right
            if(c+1 < grid[0].size() && grid[r][c+1] == INT_MAX)
            {
                grid[r][c+1] = grid[r][c] + 1;
                q.push({r,c+1});
            }
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;


        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                // collect all the treasure chest at once
                if(grid[i][j] == 0)
                {
                    q.push({i,j});
                }
            }
        }

        // 
        bfs(grid,q);
    }
};
