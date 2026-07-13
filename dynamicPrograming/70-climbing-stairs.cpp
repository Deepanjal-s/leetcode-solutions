#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:

    int climbStairs(int n) {
        int curr = 1;
        int prev2 = 0;
        int prev1 = 1;

        for(int i = 3; i <= n; i++){
            curr = prev2 + prev1;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};

int main() {
    int n = 5;
    Solution obj;
    cout << obj.climbStairs(n); 
    return 0;
}