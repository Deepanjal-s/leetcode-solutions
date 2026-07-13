#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> curr(n, INT_MAX);
        curr[src] = 0;

        for(int i = 0; i < k+1; i++){
            vector<int> temp = curr;
            for(int j = 0; j < flights.size(); j++){
                if(curr[flights[j][0]] != INT_MAX){
                    int curCost = curr[flights[j][0]] + flights[j][2];
                    if(temp[flights[j][1]] > curCost){
                        temp[flights[j][1]] = curCost;
                    }
                }
            }
            curr = temp;
        }
        return (curr[dst] != INT_MAX) ? curr[dst]: -1;
    }
};