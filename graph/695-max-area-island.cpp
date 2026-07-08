#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int Max = 0;
        int row = grid.size();
        int col = grid[0].size();

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 1){
                    Max = max(Max,backtrack(grid,i,j));
                }
            }
        }
        return Max;
    }


    int backtrack(vector<vector<int>>& grid, int row, int col){
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()){
            return 0;
        }

        
        if(grid[row][col] != 1){
            return 0;
        } 
        int count =  1;

        grid[row][col] = 0;

        count += backtrack(grid,row+1,col);
        count += backtrack(grid,row-1,col);
        count += backtrack(grid,row,col+1);    
        count += backtrack(grid,row,col-1);
        return count;
    }
    
};