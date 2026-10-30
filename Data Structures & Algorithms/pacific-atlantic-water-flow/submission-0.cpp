class Solution {
public:
    void bfs(queue<pair<int, int>>& q, vector<vector<bool>>& ocean,
             const vector<vector<int>>& heights) 
             {
                int m = heights.size();
                int n = heights[0].size();

                while(!q.empty())
                {
                    pair<int,int> front = q.front();
                    q.pop();
                    int r = front.first;
                    int c = front.second;

                    //check in all direction
                    //up (r-1,c)
                    if(r-1>=0 && !ocean[r-1][c] && heights[r-1][c] >= heights[r][c])
                    {
                        ocean[r-1][c] = true;
                        q.push({r-1,c});
                    }

                    // Down: (r + 1, c)
                    if (r + 1 < m && !ocean[r + 1][c] && heights[r + 1][c] >= heights[r][c]) 
                    {
                        ocean[r + 1][c] = true;
                        q.push({r + 1, c});
                    }

                    // Left: (r, c - 1)
                    if (c - 1 >= 0 && !ocean[r][c - 1] && heights[r][c - 1] >= heights[r][c]) 
                    {
                        ocean[r][c - 1] = true;
                        q.push({r, c - 1});
                    }

                    // Right: (r, c + 1)
                    if (c + 1 < n && !ocean[r][c + 1] && heights[r][c + 1] >= heights[r][c]) 
                    {
                        ocean[r][c + 1] = true;
                        q.push({r, c + 1});
                    }


                }
             }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        vector<vector<int>> result;
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pasific(m, vector<bool>(n, false));

        vector<vector<bool>> ataliantic(m, vector<bool>(n, false));
        /*
        pasific false   false   false   false   false
                false   false   false   false   false
                false   false   false   false   false
                false   false   false   false   false
                false   false   false   false   false
        */

        // fill the pasific and ataliantic border size
        queue<pair<int, int>> pacificqueue;
        queue<pair<int, int>> atalianticqueue;

        // 1. top row and bottom row
        for (int c = 0; c < n; c++) 
        {
            pasific[0][c] = true;
            pacificqueue.push({0, c});

            ataliantic[m - 1][c] = true;
            atalianticqueue.push({m - 1, c});
        }

        // 2. Left column and right column
        for (int r = 0; r < m; r++) 
        {
            pasific[r][0] = true;
            pacificqueue.push({r, 0});

            ataliantic[r][n - 1] = true;
            atalianticqueue.push({r, n - 1});
        }

        // Instead of checking every single cell to see if water runs
        // downhill(<=) to ocean , start at the ocean borders and run BFS/DFS
        // inword
        bfs(pacificqueue, pasific, heights);
        bfs(atalianticqueue, ataliantic, heights);

        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (pasific[i][j] && ataliantic[i][j]) 
                {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};