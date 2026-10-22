class Solution {
public:
    int bfs(vector<vector<int>>& grid,int row,int col)
    {
        int area = 1;
        queue<pair<int,int>> q;
        q.push({row,col});
        grid[row][col] = 0;

        while(!q.empty())
        {
            pair<int,int> curr = q.front();
            q.pop();
            int r = curr.first;
            int c = curr.second;

            // up 
            if(r-1 >=0 && grid[r-1][c] == 1)
            {
                grid[r-1][c] = 0;
                //sink immediately on push
                q.push({r-1,c});
                area++;
            }

            // down
            if(r+1 < grid.size() && grid[r+1][c] == 1)
            {
                grid[r+1][c] = 0;
                q.push({r+1,c});
                area++;
            }

            // left
            if(c-1 >=0 && grid[r][c-1] == 1)
            {
                grid[r][c-1] = 0;
                q.push({r,c-1});
                area++;
            }

            // right
            if(c+1 < grid[row].size() && grid[r][c+1] == 1)
            {
                grid[r][c+1] = 0;
                q.push({r,c+1});
                area++;
            }

        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // okay same as numbers of island problem
        // what is my plan
        // 1. iterate through the grid 
        int maxarea = 0;

        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 1)
                {
                    maxarea = max(maxarea,bfs(grid,i,j));
                }
            }
        }

        return maxarea;
        // if it's land then call bfs for counting countinus land
        // return the max area


    }
};
