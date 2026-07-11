#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;

        fillBoard(board,0,ans);
        return ans;
    }

    bool fillBoard(vector<string>& board, int index,vector<vector<string>>& ans){
        if(index == board.size()){
            ans.push_back(board);
            return true;
        }

        for(int i = 0; i < board.size(); i++){
            if(isValid(board,i,index)){
                board[i][index] = 'Q';
                fillBoard(board,index+1,ans);
                board[i][index] = '.';
            }
        }
    }

    bool isValid(vector<string>& board, int row, int col){
        for(int i = 0; i < col; i++){
            if(board[row][i] == 'Q'){
                return false;
            }
        }

        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        for(int i = row,j = col; i < board.size() && j >= 0; i++, j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        return true;
    }
};
