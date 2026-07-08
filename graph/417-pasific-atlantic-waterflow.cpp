#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if(heights.empty()) return heights;
        vector<vector<bool>> left = leftGrid(heights);
        vector<vector<bool>> right = rightGrid(heights);
        vector<vector<int>> grid;
        int row = heights.size();
        int col = heights[0].size();
        for(int i = 1; i < row; i++){
            for(int j = 1; j < col; j++){
                if(left[i][j] == right[i][j]){
                    grid[i][j+1] = true;
                }else{
                    grid[i][j+1] = false;
                }
            }
        }
        return grid;
    }

    vector<vector<bool>> leftGrid(vector<vector<int>>& heights){
        vector<vector<bool>> grid;
        int row = heights.size();
        int col = heights[0].size();
        
        for(int i = 0; i < row; i++){
            grid[i][0] = true;
        }

        for(int j = 0; j < col; j++){
            grid[0][j] = true;
        }

        for(int i = 1; i < row; i++){
            for(int j = 1; j < col; j++){
                if((heights[i][j] - heights[i][j+1]) <= 0){
                    grid[i][j+1] = true;
                }else{
                    grid[i][j+1] = false;
                }

                if((heights[i][j] - heights[i+1][j]) <= 0){
                    grid[i+1][j] = true;
                }else{
                    grid[i+1][j] = false;
                }
            }
        }
        return grid;
    }

    vector<vector<bool>> rightGrid(vector<vector<int>>& heights){
        vector<vector<bool>> grid;
        int row = heights.size();
        int col = heights[0].size();
        
        for(int i = row; i > 0; i--){
            grid[i][0] = true;
        }

        for(int j = col; j > 0; j--){
            grid[0][j] = true;
        }

        for(int i = row; i > 0; i--){
            for(int j = col; j > 0; j--){
                if((heights[i][j] - heights[i][j-1]) >= 0){
                    grid[i][j-1] = true;
                }else{
                    grid[i][j-1] = false;
                }

                if((heights[i][j] - heights[i-1][j]) >= 0){
                    grid[i-1][j] = true;
                }else{
                    grid[i-1][j] = false;
                }
            }
        }
        return grid;
    }
};