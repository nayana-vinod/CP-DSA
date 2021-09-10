// QUESTION: https://leetcode.com/problems/valid-sudoku/

// Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

// Each row must contain the digits 1-9 without repetition.
// Each column must contain the digits 1-9 without repetition.
// Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
// Note:
// A Sudoku board (partially filled) could be valid but is not necessarily solvable.
// Only the filled cells need to be validated according to the mentioned rules.

// SOLUTION 1: not complete
class Solution {
public:
    
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_multimap<string, char> sudoku;
        
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.') continue;
                
                string row = "row"+to_string(i);
                string col = "col"+to_string(j);
                string block = "block"+to_string(i/3)+to_string(j/3);
                if(sudoku.find(row)->second == board[i][j] ||
                  sudoku.find(col)->second == board[i][j] || 
                  sudoku.find(block)->second == board[i][j]) return false;
                
                sudoku.insert({ {row, board[i][j]}, 
                               {col, board[i][j]}, 
                               {block, board[i][j]},
                              });
            }
        }
        return true;
    }
};

// SOLUTION 2: Runtime: 40 ms, faster than 8.24%
class Solution {
public:
    
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<string, char> sudoku;
        
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.') continue;
                
                string ch = to_string(board[i][j]);
                string row = to_string(i)+ "row" +ch;
                string col = to_string(j)+ "col" +ch;
                string block = to_string(i/3)+to_string(j/3)+ "block" +ch;
                if(sudoku.find(row) != sudoku.end() ||
                  sudoku.find(col) != sudoku.end() || 
                  sudoku.find(block) != sudoku.end() ) return false;
                
                sudoku.insert({ {row, board[i][j]}, 
                               {col, board[i][j]}, 
                               {block, board[i][j]},
                              });
            }
        }
        return true;
    }
};

// SOLUTION 3: Runtime: 30 ms, faster than 18.07% 
class Solution {
public:
    
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> sudoku;
        
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.') continue;
                
                string ch = to_string(board[i][j]);
                string row = to_string(i)+ "row" +ch;
                string col = to_string(j)+ "col" +ch;
                string block = to_string(i/3)+to_string(j/3)+ "block" +ch;
                if(sudoku.find(row) != sudoku.end() ||
                  sudoku.find(col) != sudoku.end() || 
                  sudoku.find(block) != sudoku.end() ) return false;
                
                sudoku.insert(row);
                sudoku.insert(col);
                sudoku.insert(block);
            }
        }
        return true;
    }
};
