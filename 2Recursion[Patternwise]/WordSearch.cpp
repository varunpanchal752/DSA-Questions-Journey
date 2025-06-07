class Solution {
public:
    bool wordFinder(int row, int column, int rows, int columns, int k, vector<vector<char>>& board, string& word){
        if(k == word.size()) return true;
        if(row<0 || column<0 || row==rows || column==columns || board[row][column]!=word[k]) return false;

        char c = board[row][column];
        board[row][column] = '#';
        bool top = wordFinder(row-1, column, rows, columns, k+1, board, word);
        bool bottom = wordFinder(row+1, column, rows, columns, k+1, board, word);
        bool left = wordFinder(row, column-1, rows, columns, k+1, board, word);
        bool right = wordFinder(row , column+1, rows, columns, k+1, board, word);
        board[row][column] = c;

        return top || bottom || left || right;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows=board.size(), columns=board[0].size(), k=0;

        for(int row=0; row<rows; row++){
            for(int column=0; column<columns; column++){
                if(board[row][column] == word[k]){
                    if(wordFinder(row, column, rows, columns, k, board, word)) return true;
                }
            }
        }
        return false;
    }
};