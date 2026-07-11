#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int island = 0;
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return -1;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    island++;
                    backtrack(grid,i,j);
                }
            }
        }
        return island;
    }

    void backtrack(vector<vector<char>>& grid, int row, int col){

        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()){
            return;
        }

        if(grid[row][col] != '1'){
            return;
        }

        grid[row][col] = '0';
        
        backtrack(grid,row+1,col);
        backtrack(grid,row-1,col);
        backtrack(grid,row,col+1);
        backtrack(grid,row,col-1);
    }
};