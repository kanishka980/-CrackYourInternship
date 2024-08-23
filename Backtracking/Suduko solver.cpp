class Solution {
    
    bool findEmptyLocation(vector<vector<char>> &board, int &row, int &col) {
        for(row = 0; row < 9; row++) {
            for(col = 0; col < 9; col++) {
                if(board[row][col] == '.') {
                    return true;  
                }
            }
        }
        return false;  
    }

   
    bool isValid(vector<vector<char>> &board, int row, int col, char ch) {
        
        for(int j = 0; j < 9; j++) {
            if(board[row][j] == ch) return false;
        }
        
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == ch) return false;
        }
      
        int rf = row - (row % 3);  
        int cf = col - (col % 3);  
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[i + rf][j + cf] == ch) return false;
            }
        }
        return true;  
    }

public:
    
    bool solveSudoku(vector<vector<char>>& board) {
        int row, col;
        
        if(!findEmptyLocation(board, row, col)) {
            return true;
        }
        
        for(char c = '1'; c <= '9'; c++) {
            if(isValid(board, row, col, c)) {
                board[row][col] = c;  
                if(solveSudoku(board)) return true;  
                board[row][col] = '.';  
            }
        }
        return false;  
    }
};
