class Solution {
public:
    bool isPresent(vector<vector<char>>& board,int row, int col,int index,string &word,vector<vector<bool>>& visited)
    {
        if(index == word.length())
        {
            return true;
        }
        if(row < 0 || row == board.size() || 
            col < 0 || col == board[0].size())
        {
            return false;
        }

        if( visited[row][col] )
        {
            return false;
        }

        if(board[row][col] == word[index])
        {
            visited[row][col] = true;
            bool found = isPresent(board, row - 1, col, index + 1, word, visited) ||
                    isPresent(board, row + 1, col, index + 1, word, visited) ||
                    isPresent(board, row, col - 1, index + 1, word, visited) ||
                    isPresent(board, row, col + 1, index + 1, word, visited);

            visited[row][col] = false; // backtrack

            return found;
        }

        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();

        vector<vector<bool>> visited(row,vector<bool>(col,false));        
        bool ans = false;
        for(int i = 0;i<row;i++)
        {
            for(int j = 0;j<col;j++)
            {
                if(word[0] == board[i][j])
                {
                    ans = isPresent(board,i,j,0,word,visited); 
                    if(ans) return true;
                }
            }
        }

        return ans;
    }
};