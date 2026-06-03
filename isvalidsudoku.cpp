#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    int N = 9;

    vector<unordered_set<char>> column(9);
    vector<unordered_set<char>> row(9);
    vector<unordered_set<char>> box(9);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            char val = board[i][j];

            if(val == '.'){
                continue;
            }

            //check if row contains that value
            if(row[i].count(val)){
                return false;
            }
            row[i].insert(val);
            //if column contains that value

            if(column[j].count(val)){
                return false;
            }
            column[j].insert(val);

            int bx = (i/3)*3 + j/3;
            if(box[bx].count(val)){
                return false;
            }
            box[bx].insert(val);
        }
    }
    return true;
}


int main(){

    vector<vector<char>> nums = {
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    bool result = isValidSudoku(nums);

    cout << result << endl;

}