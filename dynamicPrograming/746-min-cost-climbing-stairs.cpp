#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int,int> memo;
    
    int minCostClimbingStairs(vector<int>& cost) {
        
    }

    int climb(int n){
        
        int prev2 = 1;
        int prev1 = 2;

        for(int i = 0; i <= n; i++){
            int curr = prev2 + prev1;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};