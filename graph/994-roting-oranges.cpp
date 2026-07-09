#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int count = 0;
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return -1;
        queue<pair<int,int>> q;
        int minutes = 0;
        int freshCount = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                if(grid[i][j] == 1){
                    freshCount++;
                }
            }
        }

        if(freshCount == 0) return 0;
        
        int dc[4] = {1,-1,0,0};
        int dr[4] = {0,0,1,-1};

        while(!q.empty()){
            int size = q.size();
            bool rotten = false;

            for(int i = 0; i < size; i++){
                auto [row, col] = q.front();
                q.pop();

                for(int k = 0; k < 4; k++){
                    int nr = row+dr[k];
                    int nc = col+dc[k];
                    if(nr < 0 || nc < 0 || nr >= grid.size() || nc >= grid[0].size() || grid[nr][nc] != 1) continue;
                    
                    grid[nr][nc] = 2;
                    freshCount--;
                    q.push({nr,nc});
                    rotten = true;
                }
                if(rotten) minutes++;
            }
        }
        return freshCount == 0 ? minutes : -1; 
    }
};