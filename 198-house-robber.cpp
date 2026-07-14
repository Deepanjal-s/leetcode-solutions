#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums){
        int rob1 = 0;
        int rob2 = 0; 
        int maxofprev = 0;

        for(int i = 0; i < nums.size(); i++){
            maxofprev = max(nums[i]+rob1,rob2);
            rob1 = rob2;
            rob2 = rob1;
        }

        return rob2;
    }
};