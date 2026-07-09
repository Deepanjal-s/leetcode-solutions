#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if(heights.empty()) return heights;
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<bool>> left(row, vector<bool>(col, false));
        vector<vector<bool>> right(row, vector<bool>(col, false));
        vector<vector<int>> grid;
        
        for(int i = 0; i < row; i++){
            dfs(heights,left,i,0);
            dfs(heights,right,i,col-1);
        }

        for(int j = 0; j < col; j++){
            dfs(heights,left,0,j);
            dfs(heights,right,row-1,j);
        }

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(left[i][j] && right[i][j]){
                    grid.push_back({i,j});
                }
            }
        }
        return grid;
    }

    void dfs(vector<vector<int>>& heights,vector<vector<bool>>& grid, int row, int col){
        grid[row][col] = true;
        int dr[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
        
        for(auto& d: dr){
            int ni = row+d[0];
            int nj = col+d[1];
            if(ni < 0 || nj < 0 || ni >= heights.size() || nj >= heights[0].size() || grid[ni][nj]) continue;
            if(heights[row][col] > heights[ni][nj]) continue;
            dfs(heights,grid,ni,nj);
        }
    }
};