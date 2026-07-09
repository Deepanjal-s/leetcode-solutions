#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if( i == 0 || j == 0 || i == board.size() -1  || j == board[0].size() -1  && board[i][j] == 'O'){
                    dfs(board,i,j);
                }
            }
        }

        for(int i = 0; i < board.size(); i++){
            cout << "\n";
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }else if(board[i][j] == 'T'){
                    board[i][j] = 'O';
                }
                cout << board[i][j] << " ";
            }
        }

    
    }

    void dfs(vector<vector<char>>& board,int row,int col){
        if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] != 'O'){
            return;
        }

        board[row][col] = 'T';
        dfs(board,row+1,col);
        dfs(board,row-1,col);
        dfs(board,row,col+1);
        dfs(board,row,col-1);
    }
};

int main(){
    vector<vector<char>> board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    Solution obj;
    obj.solve(board);
    return 0;
}
