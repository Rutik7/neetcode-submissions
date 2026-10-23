class Solution {
public:
    int bfs(vector<vector<int>>& grid, queue<pair<int,int>>& q, int &oranges)
    {
        int time = 0;
        while(!q.empty() && oranges > 0)
        {
            int sz = q.size();
            for(int i = 0;i<sz;i++)
            {
                pair<int,int> curr = q.front();
                q.pop();
                int r = curr.first;
                int c = curr.second;

                // up 
                if(r-1 >=0 && grid[r-1][c] == 1)
                {
                    grid[r-1][c] = 2;
                    //sink immediately on push
                    q.push({r-1,c});
                    oranges--;
                }

                // down
                if(r+1 < grid.size() && grid[r+1][c] == 1)
                {
                    grid[r+1][c] = 2;
                    q.push({r+1,c});
                    oranges--;
                }

                // left
                if(c-1 >=0 && grid[r][c-1] == 1)
                {
                    grid[r][c-1] = 2;
                    q.push({r,c-1});
                    oranges--;
                }

                // right
                if(c+1 < grid[r].size() && grid[r][c+1] == 1)
                {
                    grid[r][c+1] = 2;
                    q.push({r,c+1});
                    oranges--;
                }
            }
                time++;
            
        }
        return time;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        int oranges = 0;
        int m  = grid.size();
        int n  = grid[0].size();
        queue<pair<int,int>> q;

        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                // count fruit;
                if(grid[i][j] == 1) oranges++;

                // feed the rotten fruit to the queue 
                if(grid[i][j] == 2)
                {
                    q.push({i,j});
                }

            }
        }

        time = bfs(grid,q,oranges);


        return oranges>0 ? -1 : time;
    }
};
