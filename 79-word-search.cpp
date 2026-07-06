#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<char>> board;
    int rows ;
    int cols;

    bool exist(vector<vector<char>>& board, string word) {
        this->board = board;
        this->rows = board.size();
        this->cols = board[0].size();


        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(find(i,j,word,0)){
                    return true;
                }
            }
        }
        return false;
    }

    bool find(int i, int j, string& word, int index){
      
        if(index >= word.size()){
            return true;
        }

        if(i < 0 || j < 0 || i >= rows || j >= cols || board[i][j] != word[index]){
            return false;
        }
        
       

        

        char temp = board[i][j];
        board[i][j] = '#';

        bool found =
            find(i + 1, j, word, index + 1) ||
            find(i - 1, j, word, index + 1) ||
            find(i, j + 1, word, index + 1) ||
            find(i, j - 1, word, index + 1);

        board[i][j] = temp;

        return found;
    }
};