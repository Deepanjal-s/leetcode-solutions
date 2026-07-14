#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    
    
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() == 1) return cost[0];
        if(cost.size() == 2) return min(cost[0],cost[1]);
        int prev2 = cost[0];
        int prev1 = cost[1];

        for(int i = 2; i < cost.size(); i++){
            int curr = min(prev2 ,prev1) + cost[i];
            prev2 = prev1;
            prev1 = curr;
        }

        return min(prev2 ,prev1);   
    }
};