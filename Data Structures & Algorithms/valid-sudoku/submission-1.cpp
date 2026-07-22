class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row[9];
        unordered_set<char> col[9];
        unordered_set<char> box[9];

        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j] != '.')
                {
                    char ch = board[i][j];
                    int boxIndex = (i/3)*3 +(j/3);

                    if(row[i].find(ch) == row[i].end() && col[j].find(ch) == col[j].end() && box[boxIndex].find(ch) == box[boxIndex].end())
                    {
                        row[i].insert(ch);
                        col[j].insert(ch);
                        box[boxIndex].insert(ch);
                    }
                    else 
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};