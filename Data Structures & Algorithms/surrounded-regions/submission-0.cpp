class Solution {
public:

    void bfs(vector<vector<char>>& board, queue<pair<int,int>>& q)
    {
        int m = board.size();
        int n = board[0].size();

        while(!q.empty())
        {
            //fetch the front
            pair<int,int> front = q.front();
            q.pop();

            int r = front.first;
            int c = front.second;

            // up 
            if(r-1 >=0 && board[r-1][c] == 'O')
            {
                board[r-1][c] = '#';
                q.push({r-1,c});
            }

            // Down: (r + 1, c)
            if (r + 1 < m && board[r + 1][c] == 'O') 
            {
                board[r + 1][c] = '#';
                q.push({r + 1, c});
            }

            // Left: (r, c - 1)
            if (c - 1 >= 0 && board[r][c - 1] == 'O') 
            {
                board[r][c - 1] = '#';
                q.push({r, c - 1});
            }

            // Right: (r, c + 1)
            if (c + 1 < n && board[r][c + 1] == 'O') 
            {
                board[r][c + 1] = '#';
                q.push({r, c + 1});
            }
        }
    }
    void solve(vector<vector<char>>& board) {

        if(board.empty() || board[0].empty()) return;
        int m = board.size();
        int n = board[0].size();

        queue<pair<int,int>> q;

        // boundary loop that push 'O' into queue;
        for(int i = 0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                // process only boundary cell
                if(i == 0 || i == m-1 || j == 0 || j == n-1)
                {
                    if(board[i][j] == 'O')
                    {
                        board[i][j] = '#';
                        q.push({i,j});
                        bfs(board,q);
                    }
                }
            }
        }

        // now replacement of 'O' to 'X'
        // and # to O

        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (board[i][j] == 'O') 
                {
                    board[i][j] = 'X';
                } 
                else if (board[i][j] == '#') 
                {
                    board[i][j] = 'O';
                }
            }
        }

    }
};