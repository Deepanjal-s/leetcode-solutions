#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int left = grid[0][0];
        int right = n*n -1;
        
        while(left < right){
            int mid = left + (right - left)/2;
            if(canSwim(grid,mid)){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }

    bool canSwim(vector<vector<int>>& grid, int mid){
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        return dfs(grid,visited,0,0,mid);
    }

    bool dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j, int t){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || visited[i][j] || grid[i][j] > t){
            return false;
        }

        if(i == grid.size()-1 && j == grid.size()-1){
            return true;
        }
        visited[i][j] = true;
        return dfs(grid,visited,i+1,j,t) || dfs(grid,visited,i-1,j,t) || dfs(grid,visited,i,j+1,t) || dfs(grid,visited,i,j-1,t);
    }
};