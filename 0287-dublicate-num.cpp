#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);

        slow = nums[0];

        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return nums[slow];
    }
};

int main(){
    vector<int> nums = {1,2,4,3,3};
    Solution obj;
    int ans = obj.findDuplicate(nums);

    cout << ans << "";

    return 0;
}