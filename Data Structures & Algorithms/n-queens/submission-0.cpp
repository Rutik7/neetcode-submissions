class Solution {
public:

    bool issafe(vector<string>& board, int row,int col)
    {
        // same column
        for(int i = 0;i<row;i++)
        {
            if(board[i][col] == 'Q')
                return false;
        }

        
        for(int i = 0;i<row; i++)
        {
            for(int j = 0;j<board[row].size();j++)
            {
                // upper left diagonal
                if(i-j == row-col && board[i][j] == 'Q')
                    return false;

                // upper right diagnal
                if(i+j == row+col && board[i][j] == 'Q') 
                    return false;
            }
        }

        
        return true;
    }

    void helper(int n,int queens,vector<string>& board, vector<vector<string>>& result , int row , int col)
    {
        //my thought process is 
        // if row == n means all row has queens  
        if(row == n)
        {
            result.push_back(board);
            return;
        }


        // place the queen in 1st row and then placed in next row

        for(int i = 0;i<board[row].size();i++)
        {
            // place the queen in that row 
            // check issafe 
            if(issafe(board,row,i))
            {
                board[row][i] = 'Q';
                // try for next row 
                helper(n,queens-1,board,result,row+1,i);
                // backtrack
                board[row][i] = '.';
            }
            
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        
        vector<string> board(n, string(n, '.'));

        helper(n, n, board,result,0,0);
        return result;
    }
};