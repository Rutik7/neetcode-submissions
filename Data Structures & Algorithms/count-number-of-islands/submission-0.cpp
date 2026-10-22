class Solution {
public:
    void bfs(vector<vector<char>>& grid,int row,int col)
    {
        queue<pair<int,int>> q;
        q.push({row,col});
        grid[row][col] = '0';

        while(!q.empty())
        {
            pair<int,int> curr = q.front();
            q.pop();
            int r = curr.first;
            int c = curr.second;

            // up 
            if(r-1 >=0 && grid[r-1][c] == '1')
            {
                grid[r-1][c] = '0';
                //sink immediately on push
                q.push({r-1,c});
            }

            // down
            if(r+1 < grid.size() && grid[r+1][c] == '1')
            {
                grid[r+1][c] = '0';
                q.push({r+1,c});
            }

            // left
            if(c-1 >=0 && grid[r][c-1]=='1')
            {
                grid[r][c-1]='0';
                q.push({r,c-1});
            }

            // right
            if(c+1 < grid[row].size() && grid[r][c+1]=='1')
            {
                grid[r][c+1] = '0';
                q.push({r,c+1});
            }

        }

    }
    int numIslands(vector<vector<char>>& grid) {
        // convert 1 to 0 directly in the grid for visited land
        int count = 0;
        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                // ignore the water
                if(grid[i][j] == '1')
                {
                    count +=1;
                    // now BFS 
                    bfs(grid,i,j);
                }
            }
        }

        return count;
    }
};