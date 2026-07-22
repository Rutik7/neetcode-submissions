class Solution {
public:
    bool hasCorrectPosition(vector<vector<char>>& board, int row, int col)
    {
        //check current element is present in Row or not
        //col = i
        for(int i=0;i<9;i++)
        {
            if((col != i) && (board[row][col] == board[row][i]) )
                return false;
        }

        // check current element is present on coloum or not
        // i = row
        for (int i = 0;i<9;i++)
        {
            if(i != row && board[row][col] == board[i][col])
                return false;
        }

        // now check in 3*3 matrix
        int startRow = (row/3)*3;
        int startCol = (col/3)*3;
        for(int i = startRow;i<startRow+3;i++)
        {
            for (int j = startCol;j<startCol+3;j++)
            {
                if((i != row && j!=col) && board[row][col] == board[i][j])
                    return false;
            }
        }

        //otherwise 
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0 ;i<9;i++)
        {
            for (int j=0;j<9;j++)
            {
                if(board[i][j] == '.') continue;

                if(hasCorrectPosition(board,i,j) == 0) return false;
            }
        }

        return true;
    }
};