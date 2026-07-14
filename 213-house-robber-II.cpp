#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums){
        int rob1 = 0;
        int rob2 = 0; 
        int maxofprev = 0;

        for(int i = 0; i < nums.size() - 1; i++){
            maxofprev = max(nums[i]+rob1,rob2);
            rob1 = rob2;
            rob2 = maxofprev;
        }

        int roby1 = 0;
        int roby2 = 0; 
        int maxofprevy = 0;

        for(int i = 1; i < nums.size(); i++){
            maxofprevy = max(nums[i]+roby1,roby2);
            roby1 = roby2;
            roby2 = maxofprevy;
        }

        return max(maxofprev,maxofprevy);
    }
};