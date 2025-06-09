// Solution 1 
class Solution {
public:
    bool isSafe(int n, int row, int col, vector<string>& board){
        int dupRow = row;
        int dupCol = col;
        //left
        while(col>=0){
            if(board[row][col--] == 'Q') return false;
        }

        col = dupCol;
        //upper diagonal
        while(row>=0 && col>=0){
            if(board[row--][col--] == 'Q') return false;
        }

        row = dupRow;
        col = dupCol;
        //lower diagonal
        while(row<n && col>=0){
            if(board[row++][col--] == 'Q') return false;
        }

        return true;
    }

    void placeQueen(int n, int col, vector<vector<string>>& ans, vector<string>& board){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row=0; row<n; row++){
            if(isSafe(n, row, col, board)){
                board[row][col] = 'Q';
                placeQueen(n, col+1, ans, board);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.'); 

        for(int i=0; i<n; i++){  
            board[i] = s;
        }

        placeQueen(n, 0, ans, board);
        return ans;
    }
};


// Solution 2 (Optimal)
class Solution {
public:
    void placeQueen(int n, int col, vector<vector<string>>& ans, vector<string>& board, 
    vector<int>& leftVisited, vector<int>& upperDiagonalVisited, vector<int>& lowerDiagonalVisited)
    {
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row=0; row<n; row++){
            if(leftVisited[row] == 0 && lowerDiagonalVisited[row+col] == 0 && 
                upperDiagonalVisited[n-1+col-row] == 0)
            {
                board[row][col] = 'Q';
                leftVisited[row] = 1;
                lowerDiagonalVisited[row + col] = 1;  
                upperDiagonalVisited[n - 1 + col - row] = 1;

                placeQueen(n, col+1, ans, board, leftVisited, upperDiagonalVisited, lowerDiagonalVisited);

                board[row][col] = '.';
                leftVisited[row] = 0;
                lowerDiagonalVisited[row + col] = 0;  
                upperDiagonalVisited[n - 1 + col - row] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.'); 

        for(int i=0; i<n; i++){  
            board[i] = s;
        }

        vector<int> leftVisited(n, 0), upperDiagonalVisited(2*n - 1, 0), lowerDiagonalVisited(2*n - 1, 0);

        placeQueen(n, 0, ans, board, leftVisited, upperDiagonalVisited, lowerDiagonalVisited);
        return ans;
    }
};